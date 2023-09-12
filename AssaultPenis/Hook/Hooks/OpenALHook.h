#pragma once

// includes
#include "../../Libs/imgui/imgui_impl_opengl3.h"
#include "../../Libs/imgui/imgui_impl_win32.h"

// wglSwapBuffers is the pointer I get from GetProcAddress
void* wglSwapBuffers;

// original wglSwapBuffers call I get from minhook (not sure if their the same which they probably are)
// not gonna check either
static std::add_pointer_t<BOOL WINAPI(HDC)> __o__wglSwapBuffers;

static BOOL hkWglSwapBuffersDetour(HDC hdc) {
	// does imgui have a context?
	if (ImGui::GetCurrentContext()) {
		if (!ImGui::GetIO().BackendRendererUserData)
			ImGui_ImplOpenGL3_Init();

		// new frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		// draw basic imgui menu
		ImGui::Begin("AssaultPenis");
		ImGui::Text("AssaultPenis by yeemi#0");

		// add each module to the imgui menu
		for (auto& mod : modules) {
			std::stringstream doubleBuffer;
			doubleBuffer << "[" << (mod->enabled ? "x" : " ") << "] " << "[" << mod->keybind << "] " << mod->name << std::endl;
			
			// avoid weird artifacts
			std::string text = doubleBuffer.str();

			// draw text
			ImGui::Text(text.c_str());
		}

		ImGui::End();

		// render imgui
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	// call original wglSwapBuffers (present)
	return __o__wglSwapBuffers(hdc);
}

class OpenALHook : public FuncHook {
public:
	void* GetAssaultCubeHWND() {
		// get window of title "Assault Cube"
		return FindWindowA(nullptr, "AssaultCube");
	}

	bool Initialize() override {
		// init openal/gl hook
		std::cout << "Installing OpenAL Hook..." << std::endl;

		HMODULE openGL32 = GetModuleHandleA("opengl32.dll");

		if (!openGL32)
			return false; // no openGL32.dll (avoid crashes)

		std::cout << "Found opengl32.dll" << std::endl;

		wglSwapBuffers = (void*)GetProcAddress(openGL32, "wglSwapBuffers");

		if (!wglSwapBuffers)
			return false; // no wglSwapBuffers in opengl32 (avoid crashes)

		std::cout << "Found wglSwapBuffers" << std::endl;

		// initalize context here
		if (!ImGui::GetCurrentContext()) // we dont want to double down on the context
		{
			// create imgui context
			ImGui::CreateContext();
			ImGui_ImplWin32_Init(GetAssaultCubeHWND());

			// set imgui io
			ImGuiIO& io = ImGui::GetIO();
			io.IniFilename = io.LogFilename = nullptr; // dont save
			io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // enable keyboard controls
		}

		if (not HookFunction(wglSwapBuffers, &hkWglSwapBuffersDetour, &__o__wglSwapBuffers))
			return false; // failed to hook wglSwapBuffers

		std::cout << "Hooked wglSwapBuffers, hook fully functional" << std::endl;

		return true;
	}

	void Uninitialize() {
		MH_DisableHook(wglSwapBuffers); // disable hook

		// check if imgui has a context
		if (ImGui::GetCurrentContext()) {
			// shut down opengl3 & win32
			if (ImGui::GetIO().BackendRendererUserData)
			{
				ImGui_ImplOpenGL3_Shutdown();
				ImGui_ImplWin32_Shutdown();
			}

			// destroy imgui context
			ImGui::DestroyContext();
		}
	}

	static OpenALHook& Get() {
		static OpenALHook single;
		return single;
	}
};
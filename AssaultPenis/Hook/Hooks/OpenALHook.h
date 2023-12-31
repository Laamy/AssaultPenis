#pragma once

// includes
#include "../../Libs/imgui/imgui_impl_opengl3.h"
#include "../../Libs/imgui/imgui_impl_win32.h"

// the fonts we want to use
#include "../../Font/ProductSans.h"

// wglSwapBuffers is the pointer I get from GetProcAddress
void* wglSwapBuffers;

// original wglSwapBuffers call I get from minhook (not sure if their the same which they probably are)
// not gonna check either
static std::add_pointer_t<BOOL WINAPI(HDC)> __o__wglSwapBuffers;

static BOOL hkWglSwapBuffersDetour(HDC hdc) {
	// does imgui have a context? if not then create it
	if (!ImGui::GetCurrentContext()) // we dont want to double down on the context
	{
		// create imgui context
		ImGui::CreateContext();
		ImGui_ImplWin32_Init(FindWindowA(nullptr, "AssaultCube"));

		// set imgui io
		ImGuiIO& io = ImGui::GetIO();
		io.IniFilename = io.LogFilename = nullptr; // dont save

		// import fonts
		ImGui::GetIO().Fonts->AddFontFromMemoryCompressedTTF(ProductSans_compressed_data, ProductSans_compressed_size, 48.f);

		// build fonts
		ImGui::GetIO().Fonts->Build();
	}

	if (!ImGui::GetIO().BackendRendererUserData)
		ImGui_ImplOpenGL3_Init();

	// new frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	{
		// draw basic imgui menu
		ImGui::Begin("AssaultPenis", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground);

		// push font then set font scale for current window
		ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[0]);
		ImGui::SetWindowFontSize(16); // custom method

		ImGui::Text("AssaultPenis by yeemi#0");

		// add each module to the imgui menu
		for (auto& mod : modules) {
			std::stringstream doubleBuffer;
			doubleBuffer << "[" << (mod->enabled ? "x" : " ") << "] " << "[" << keymapNames[mod->keybind] << "] " << mod->name << std::endl;

			// avoid memory bleeding (still trauamtized from uwp apps bleeding for no reason so except more of these)
			std::string text = doubleBuffer.str();

			// draw text (temp menu)
			ImGui::Text(text.c_str());
			ImGui::Text((std::string("- ") + mod->description.c_str()).c_str());
			ImGui::Text("");
		}

		ImGui::PopFont(); // restore font back to normal

		ImGui::End(); // end imgui window (the menu we're drawing currently)
	}

	ImGui::Render(); // render imgui
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData()); // render imgui draw data aswell

	// call original wglSwapBuffers (present)
	return __o__wglSwapBuffers(hdc);
}

// openal hook class
class OpenALHook : public FuncHook {
public:
	// openal hook constructor
	OpenALHook() : FuncHook("wglSwapBuffers") {}

	bool Initialize() override {
		// init openal/gl hook
		//Log("Installing OpenAL Hook...");

		// get the opengl 32bit dll module
		HMODULE openGL32 = GetModuleHandleA("opengl32.dll");

		if (!openGL32)
			return false; // no openGL32.dll (avoid crashes)

		//Log("Found opengl32.dll");

		// get wglSwapBuffers method reference from opengl 32bit module
		wglSwapBuffers = (void*)GetProcAddress(openGL32, "wglSwapBuffers");

		if (!wglSwapBuffers)
			return false; // no wglSwapBuffers in opengl32 (avoid crashes)

		//Log("Found wglSwapBuffers");

		if (not HookFunction(wglSwapBuffers, &hkWglSwapBuffersDetour, &__o__wglSwapBuffers))
			return false; // failed to hook wglSwapBuffers

		//Log("Hooked wglSwapBuffers, hook fully functional");

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
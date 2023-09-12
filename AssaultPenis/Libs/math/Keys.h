#pragma once

// Key ID's
std::map<uint64_t, std::string> keymapNames;
void VF_c() {

	keymapNames[7] = "None";
	keymapNames[8] = "Backspace";
	keymapNames[9] = "Tab";

	keymapNames[13] = "Enter";

	keymapNames[16] = "Shift";
	keymapNames[17] = "Ctrl";
	keymapNames[18] = "Alt";
	keymapNames[19] = "Pause";
	keymapNames[20] = "CapsLock";

	keymapNames[27] = "Esc";

	keymapNames[32] = "Space";
	keymapNames[33] = "PageV";
	keymapNames[34] = "Page^";
	keymapNames[35] = "End";
	keymapNames[36] = "Home";
	keymapNames[37] = "<_Arrow";
	keymapNames[38] = "^_Arrow";
	keymapNames[39] = ">_Arrow";
	keymapNames[40] = "V_Arrow";

	keymapNames[44] = "PrtScn";
	keymapNames[45] = "Insert";
	keymapNames[46] = "Delete";

	keymapNames[48] = "0";
	keymapNames[49] = "1";
	keymapNames[50] = "2";
	keymapNames[51] = "3";
	keymapNames[52] = "4";
	keymapNames[53] = "5";
	keymapNames[54] = "6";
	keymapNames[55] = "7";
	keymapNames[56] = "8";
	keymapNames[57] = "9";

	keymapNames[65] = "A";
	keymapNames[66] = "B";
	keymapNames[67] = "C";
	keymapNames[68] = "D";
	keymapNames[69] = "E";
	keymapNames[70] = "F";
	keymapNames[71] = "G";
	keymapNames[72] = "H";
	keymapNames[73] = "I";
	keymapNames[74] = "J";
	keymapNames[75] = "K";
	keymapNames[76] = "L";
	keymapNames[77] = "M";
	keymapNames[78] = "N";
	keymapNames[79] = "O";
	keymapNames[80] = "P";
	keymapNames[81] = "Q";
	keymapNames[82] = "R";
	keymapNames[84] = "S";
	keymapNames[85] = "U";
	keymapNames[86] = "V";
	keymapNames[87] = "W";
	keymapNames[88] = "X";
	keymapNames[89] = "Y";
	keymapNames[90] = "Z";

	keymapNames[96] = "NumPad0";
	keymapNames[97] = "NumPad1";
	keymapNames[98] = "NumPad2";
	keymapNames[99] = "NumPad3";
	keymapNames[100] = "NumPad4";
	keymapNames[101] = "NumPad5";
	keymapNames[102] = "NumPad6";
	keymapNames[103] = "NumPad7";
	keymapNames[104] = "NumPad8";
	keymapNames[105] = "NumPad9";
	keymapNames[106] = "NumPad*";
	keymapNames[107] = "NumPad+";

	keymapNames[109] = "NumPad-";
	keymapNames[110] = "NumPad.";
	keymapNames[111] = "NumPad/";
	keymapNames[112] = "F1";
	keymapNames[113] = "F2";
	keymapNames[114] = "F3";
	keymapNames[115] = "F4";
	keymapNames[116] = "F5";
	keymapNames[117] = "F6";
	keymapNames[118] = "F7";
	keymapNames[119] = "F8";
	keymapNames[120] = "F9";
	keymapNames[121] = "F10";
	keymapNames[122] = "F11";
	keymapNames[123] = "F12";
	keymapNames[124] = "F13";
	keymapNames[125] = "F14";
	keymapNames[126] = "F15";
	keymapNames[127] = "F16";
	keymapNames[128] = "F17";
	keymapNames[129] = "F18";
	keymapNames[130] = "F19";
	keymapNames[131] = "F20";
	keymapNames[132] = "F21";
	keymapNames[133] = "F22";
	keymapNames[134] = "F23";
	keymapNames[135] = "F24";

	keymapNames[144] = "Numpad";
	keymapNames[145] = "ScrlLock";

	keymapNames[186] = ";";
	keymapNames[187] = "=";

	keymapNames[189] = "-";
	keymapNames[190] = ".";
	keymapNames[191] = "/";

	keymapNames[0x300] = "SpcPkt";
};

namespace Keyboard
{
	// Special keys
	static const int NONE = 7;
	static const int BACKSPACE = 8;
	static const int TAB = 9;
	static const int ENTER = 13;
	static const int SHIFT = 16;
	static const int CTRL = 17;
	static const int ALT = 18;
	static const int PAUSE = 19;
	static const int CAPSLOCK = 20;
	static const int ESC = 27;
	static const int SPACEBAR = 32;
	static const int PAGEUP = 33;
	static const int PAGEDOWN = 34;
	static const int END = 35;
	static const int HOME = 36;
	static const int ARROW_LEFT = 37;
	static const int ARROW_UP = 38;
	static const int ARROW_RIGHT = 39;
	static const int ARROW_DOWN = 40;
	static const int PRINTSCRN = 44;
	static const int INSERT = 45;
	static const int DELETE_KEY = 46;

	// Number keys
	static const int NUM_0 = 48;
	static const int NUM_1 = 49;
	static const int NUM_2 = 50;
	static const int NUM_3 = 51;
	static const int NUM_4 = 52;
	static const int NUM_5 = 53;
	static const int NUM_6 = 54;
	static const int NUM_7 = 55;
	static const int NUM_8 = 56;
	static const int NUM_9 = 57;

	// Alphabet keys
	static const int A = 65;
	static const int B = 66;
	static const int C = 67;
	static const int D = 68;
	static const int E = 69;
	static const int F = 70;
	static const int G = 71;
	static const int H = 72;
	static const int I = 73;
	static const int J = 74;
	static const int K = 75;
	static const int L = 76;
	static const int M = 77;
	static const int N = 78;
	static const int O = 79;
	static const int P = 80;
	static const int Q = 81;
	static const int R = 82;
	static const int S = 83;
	static const int U = 85;
	static const int V = 86;
	static const int W = 87;
	static const int Y = 88;
	static const int X = 89;
	static const int Z = 90;
	
	// Function keys
	static const int F1 = 112;
	static const int F2 = 113;
	static const int F3 = 114;
	static const int F4 = 115;
	static const int F5 = 116;
	static const int F6 = 117;
	static const int F7 = 118;
	static const int F8 = 119;
	static const int F9 = 120;
	static const int F10 = 121;
	static const int F11 = 122;
	static const int F12 = 123;

	// Numpad keys
	static const int NUMPAD_0 = 96;
	static const int NUMPAD_1 = 97;
	static const int NUMPAD_2 = 98;
	static const int NUMPAD_3 = 99;
	static const int NUMPAD_4 = 100;
	static const int NUMPAD_5 = 101;
	static const int NUMPAD_6 = 102;
	static const int NUMPAD_7 = 103;
	static const int NUMPAD_8 = 104;
	static const int NUMPAD_9 = 105;
	static const int NUMPAD_MULTIPLY = 106;
	static const int NUMPAD_ADD = 107;
	static const int NUMPAD_SUBTRACT = 109;
	static const int NUMPAD_DECIMAL = 110;
	static const int NUMPAD_DIVIDE = 111;

	// Other keys
	static const int SEMICOLON = 186;
	static const int EQUAL = 187;
	static const int COMMA = 188;
	static const int DASH = 189;
	static const int PERIOD = 190;
	static const int FORWARDSLASH = 191;
	static const int GRAVE = 192;
	static const int LBRACKET = 219;
	static const int BACKSLASH = 220;
	static const int RBRACKET = 221;
	static const int APOSTROPHE = 222;
};
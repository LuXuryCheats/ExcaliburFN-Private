#include "include.h"
#include "Settings.h"
#include "offsets.h"

#define RELATIVE_ADDR(addr, size) ((PBYTE)((UINT_PTR)(addr) + *(PINT)((UINT_PTR)(addr) + ((size) - sizeof(INT))) + (size)))

namespace PlayerLoop
{
	void Player_Loop()
	{

	}
}

namespace menu
{

	typedef struct
	{
		DWORD R;
		DWORD G;
		DWORD B;
		DWORD A;
	}RGBA;

	class Color
	{
	public:
		RGBA red = { 300,0,0,300 };
		RGBA Magenta = { 255,0,255,255 };
		RGBA yellow = { 255,255,0,255 };
		RGBA grayblue = { 128,128,255,255 };
		RGBA green = { 128,224,0,255 };
		RGBA darkgreen = { 0,224,128,255 };
		RGBA brown = { 192,96,0,255 };
		RGBA pink = { 255,168,255,255 };
		RGBA DarkYellow = { 216,216,0,255 };
		RGBA SilverWhite = { 236,236,236,255 };
		RGBA purple = { 144,0,255,255 };
		RGBA Navy = { 88,48,224,255 };
		RGBA skyblue = { 0,136,255,255 };
		RGBA graygreen = { 128,160,128,255 };
		RGBA blue = { 0,96,192,255 };
		RGBA orange = { 255,128,0,255 };
		RGBA peachred = { 255,80,128,255 };
		RGBA reds = { 255,128,192,255 };
		RGBA darkgray = { 96,96,96,255 };
		RGBA Navys = { 0,0,128,255 };
		RGBA darkgreens = { 0,128,0,255 };
		RGBA darkblue = { 0,128,128,255 };
		RGBA redbrown = { 128,0,0,255 };
		RGBA purplered = { 128,0,128,255 };
		RGBA greens = { 0,255,0,255 };
		RGBA envy = { 0,255,255,255 };
		RGBA black = { 0,0,0,255 };
		RGBA gray = { 128,128,128,255 };
		RGBA white = { 255,255,255,255 };
		RGBA blues = { 30,144,255,255 };
		RGBA lightblue = { 135,206,250,160 };
		RGBA Scarlet = { 220, 20, 60, 160 };
		RGBA white_ = { 255,255,255,200 };
		RGBA gray_ = { 128,128,128,200 };
		RGBA black_ = { 0,0,0,200 };
		RGBA red_ = { 255,0,0,200 };
		RGBA Magenta_ = { 255,0,255,200 };
		RGBA yellow_ = { 255,255,0,200 };
		RGBA grayblue_ = { 128,128,255,200 };
		RGBA green_ = { 128,224,0,200 };
		RGBA darkgreen_ = { 0,224,128,200 };
		RGBA brown_ = { 192,96,0,200 };
		RGBA pink_ = { 255,168,255,200 };
		RGBA darkyellow_ = { 216,216,0,200 };
		RGBA silverwhite_ = { 236,236,236,200 };
		RGBA purple_ = { 144,0,255,200 };
		RGBA Blue_ = { 88,48,224,200 };
		RGBA skyblue_ = { 0,136,255,200 };
		RGBA graygreen_ = { 128,160,128,200 };
		RGBA blue_ = { 0,96,192,200 };
		RGBA orange_ = { 255,128,0,200 };
		RGBA pinks_ = { 255,80,128,200 };
		RGBA Fuhong_ = { 255,128,192,200 };
		RGBA darkgray_ = { 96,96,96,200 };
		RGBA Navy_ = { 0,0,128,200 };
		RGBA darkgreens_ = { 0,128,0,200 };
		RGBA darkblue_ = { 0,128,128,200 };
		RGBA redbrown_ = { 128,0,0,200 };
		RGBA purplered_ = { 128,0,128,200 };
		RGBA greens_ = { 0,255,0,200 };
		RGBA envy_ = { 0,255,255,200 };

		RGBA glassblack = { 0, 0, 0, 160 };
		RGBA GlassBlue = { 65,105,225,80 };
		RGBA glassyellow = { 255,255,0,160 };
		RGBA glass = { 200,200,200,60 };


		RGBA Plum = { 221,160,221,160 };
		RGBA clgreen = { 85, 208, 182, 255 };
		RGBA neongreen = { 0, 255, 229,0 };

	};
	Color Col;

	std::string string_To_UTF8(const std::string& str)
	{
		int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

		wchar_t* pwBuf = new wchar_t[nwLen + 1];
		ZeroMemory(pwBuf, nwLen * 2 + 2);

		::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);

		int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

		char* pBuf = new char[nLen + 1];
		ZeroMemory(pBuf, nLen + 1);

		::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

		std::string retStr(pBuf);

		delete[]pwBuf;
		delete[]pBuf;

		pwBuf = NULL;
		pBuf = NULL;

		return retStr;
	}

	void DrawLine(int x1, int y1, int x2, int y2, RGBA* color, int thickness)
	{
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), thickness);
	}


	bool RenderMenu = true;

	void DRAWMENUITEMCUSTOM(int x, int y, ImColor color, const char* str)
	{
		ImFont a;
		std::string utf_8_1 = std::string(str);
		std::string utf_8_2 = string_To_UTF8(utf_8_1);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), utf_8_2.c_str());
	}
	void DRAWMENUITEMCUSTOMOUTLINED(int x, int y, ImColor color, const char* str)
	{
		ImFont a;
		std::string utf_8_1 = std::string(str);
		std::string utf_8_2 = string_To_UTF8(utf_8_1);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x - 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), utf_8_2.c_str());
	}
	void DRAWMENUITEMOUTLINED(int x, int y, RGBA* color, const char* str)
	{
		ImFont a;
		std::string utf_8_1 = std::string(str);
		std::string utf_8_2 = string_To_UTF8(utf_8_1);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x - 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
	}
	void DRAWMENUITEM(int x, int y, RGBA* color, const char* str)
	{
		ImFont a;
		std::string utf_8_1 = std::string(str);
		std::string utf_8_2 = string_To_UTF8(utf_8_1);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
	}
	void DRAW(int x, int y, int w, int h, RGBA* color, int thickness)
	{
		ImGui::GetOverlayDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), 0, 0, thickness);
	}
	void TITLEBAR(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), 0, 0);
	}
	void TITLEBARGRADIENT(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), (color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0), 0, 0);
		ImGui::GetOverlayDrawList()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), (color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0), 0, 0);
		ImGui::GetOverlayDrawList()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), (color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0), 0, 0);
		ImGui::GetOverlayDrawList()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), (color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0), 0, 0);
	}

	void MENUBG(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, 0.70f)), 0, 0);
	}

	void MENUBGCUSTOM(int x, int y, int w, int h, ImColor color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), 0, 0);
	}

	void MENUBGCUSTOMGRAD(int x, int y, int w, int h, ImColor color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), 0, 0);
	}

	void MENUBGFILLED(int x, int y, int w, int h, ImColor color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), 0, 0);
	}

	void SELECTED(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, 0.40f)), 0, 0);
	}

	void MENUBGFILLED(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, 1.00f)), 0, 0);
	}

	void MENUBGFILLEDGRAD(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, 1.00f)), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, 1.00f)), 0, 0);
	}

	void WaterMark()
	{
		if (Settings::WaterMark)
		{
			int x = 20;
			int y = 30;

			if (Settings::AimFOV_Enable == true)
			{
				DRAWMENUITEM(x + 800, y + 45, &Col.white, ("SQUARE ENABLED : AIM TYPE: MEMORY : AIM BONE: [HEAD]"));
			}

			DRAWMENUITEM(x + 800, y + 18, &Col.purple, ("MOUSE AIMBOT BUTTON || RUBTTON/RMB/RIGHT MOUSE BUTTON"));
			DRAWMENUITEM(x + 800, y + 45, &Col.white, ("SQUARE FALSE : AIM TYPE: DISABLED : AIM BONE: [HEAD]"));
			DRAWMENUITEM(x + 800, y + 30, &Col.red, ("Excalibur Fortnite Private | Status UNDETECTED WORKING!"));
		}
	}

	void FOV()
	{
		float AimFOV = 200.f;

		if (Settings::AimFOV_Enable)
		{

		}
	}

	ImVec2 p;
	ImDrawList* draw;
	/*
	void Settings()
	{
		if (Settings::Corner_ESP == false)
		{
			DRAWMENUITEM(p.x + 204, p.y + 65, &Col.white, ("False"));
		}

		if (Settings::Corner_ESP == true)
		{
			DRAWMENUITEM(p.x + 204, p.y + 65, &Col.white, (" True"));
		}

		if (Settings::Lines == false)
		{
			DRAWMENUITEM(p.x + 204, p.y + 85, &Col.white, ("False"));
		}

		if (Settings::Lines == true)
		{
			DRAWMENUITEM(p.x + 204, p.y + 85, &Col.white, (" True"));
		}

		if (Settings::AimFOV_Enable == false)
		{
			DRAWMENUITEM(p.x + 204, p.y + 105, &Col.white, ("False"));
		}

		if (Settings::AimFOV_Enable == true)
		{
			DRAWMENUITEM(p.x + 204, p.y + 105, &Col.white, (" True"));
		}

		if (Settings::Aimbot == false)
		{
			DRAWMENUITEM(p.x + 204, p.y + 125, &Col.white, ("False"));
		}

		if (Settings::Aimbot == true)
		{
			DRAWMENUITEM(p.x + 204, p.y + 125, &Col.white, (" True"));
		}

		if (Settings::AimFOV_Enable == false)
		{
			DRAWMENUITEM(p.x + 204, p.y + 105, &Col.white, (" True"));
		}

		if (Settings::AimFOV_Enable == true)
		{
			DRAWMENUITEM(p.x + 204, p.y + 105, &Col.white, (" True"));
		}

		if (Settings::AimFOV_Enable == false)
		{
			DRAWMENUITEM(p.x + 204, p.y + 105, &Col.white, (" True"));
		}

		if (Settings::AimFOV_Enable == true)
		{
			DRAWMENUITEM(p.x + 204, p.y + 105, &Col.white, (" True"));
		}
	}*/

	void SugarHookGang()
	{
		FOV();

		static bool pressed = false;

		if (GetKeyState(VK_INSERT) & 0x8000) //change menu key here
			pressed = true;

		else if (!(GetKeyState(VK_INSERT) & 0x8000) && pressed) {  //change menu key here
			RenderMenu = !RenderMenu;
			pressed = false;
		}

		if (RenderMenu)
		{
			int x = 20;
			int y = 30;
			ImGui::SetNextWindowSize({ 241 , 420 });
			ImGui::Begin(" ", 0, ImGuiWindowFlags_::ImGuiWindowFlags_NoResize | ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse);

			p = ImGui::GetWindowPos();
			draw = ImGui::GetWindowDrawList();

			std::string TITLETEXT = ("Fortnite Excalibur");

			MENUBGCUSTOM(p.x, p.y, -2, -2, ImColor(74, 2, 230));
			MENUBGCUSTOM(p.x, p.y, 243, -2, ImColor(74, 2, 230));
			MENUBGCUSTOM(p.x, p.y, 243, 420, ImColor(74, 2, 230));
			MENUBGCUSTOM(p.x, p.y, -2, 420, ImColor(74, 2, 230));
			MENUBGFILLED(p.x, p.y, 241, 418, &Col.black);
			DRAWMENUITEMCUSTOM(p.x + 4, p.y + 4, ImColor(255, 255, 255), TITLETEXT.c_str());



			DRAWMENUITEM(p.x + 204, p.y + 65, &Col.white, ("False"));
			DRAWMENUITEM(p.x + 204, p.y + 85, &Col.white, ("False"));
			DRAWMENUITEM(p.x + 204, p.y + 105, &Col.white, ("False"));
			DRAWMENUITEM(p.x + 204, p.y + 125, &Col.white, ("False"));



			DRAWMENUITEM(p.x + 7, p.y + 65, &Col.white, ("Player ESP [F1]: "));
			DRAWMENUITEM(p.x + 7, p.y + 85, &Col.white, ("Player Lines [F2]: "));
			DRAWMENUITEM(p.x + 7, p.y + 105, &Col.white, ("FOV square [F3]:"));
			DRAWMENUITEM(p.x + 7, p.y + 125, &Col.white, ("Aimbot [F4]: "));
			DRAWMENUITEM(p.x + 7, p.y + 145, &Col.white, ("Aimbot button [RM]: "));     DRAWMENUITEM(p.x + 204, p.y + 145, &Col.white, ("False"));
			DRAWMENUITEM(p.x + 7, p.y + 165, &Col.white, ("Aimbot smoothing [</>]:        2"));
			DRAWMENUITEM(p.x + 7, p.y + 185, &Col.white, ("Airstuck [F6]: "));       DRAWMENUITEM(p.x + 204, p.y + 185, &Col.white, ("False"));
			DRAWMENUITEM(p.x + 7, p.y + 205, &Col.white, ("Vehicle fly [F7]: "));    DRAWMENUITEM(p.x + 204, p.y + 205, &Col.white, ("False"));
			DRAWMENUITEM(p.x + 7, p.y + 225, &Col.white, ("Vehicle tp [F8]: "));     DRAWMENUITEM(p.x + 204, p.y + 225, &Col.white, ("False"));

			ImGui::GetOverlayDrawList()->AddRectFilled(ImGui::GetIO().MousePos, ImVec2(ImGui::GetIO().MousePos.x + 5.f, ImGui::GetIO().MousePos.y + 5.f), ImColor(139, 2, 230));

		}
	}
}
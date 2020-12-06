#define _CRT_SECURE_NO_WARNINGS

#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_internal.h"

#include <d3d11.h>
#include <d3d10.h>

#include "minhook/Minhook.h"
#pragma comment(lib, "minhook.lib")
#pragma comment(lib, "d3d11.lib")

#include <vector>
#include <string>
#include <sstream>
#include <Windows.h>

ImGuiWindow& BeginScene();
VOID EndScene(ImGuiWindow& window);

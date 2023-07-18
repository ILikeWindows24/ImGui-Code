uintptr_t moduleBase = (uintptr_t)GetModuleHandle("GameAssembly.dll");

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ImGui::SetNextWindowSize(ImVec2(400, 300));
	ImGui::Begin(("Saki - Idle Slayer"), NULL, ImGuiWindowFlags_NoResize);

	if (ImGui::InputDouble(("Cash"), &globals::Coins))
	{
		*(double*)mem::FindAddress(moduleBase + 0x01E52158, { 0xB8, 0x0, 0x10, 0x28, 0x20 }) = globals::Coins;
	}

	bool swordlvl = false;
	if (ImGui::Checkbox(("Max Level Sword"), &globals::SwordLevel))
	{
		*(bool*)mem::FindAddress(moduleBase + 0x01E452E8, { 0xB8, 0x10, 0x20, 0x10, 0x120, 0x28, 0x78 }) = globals::SwordLevel;
	}

	ImGui::End();

	ImGui::Render();

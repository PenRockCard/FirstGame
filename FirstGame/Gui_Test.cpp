#include "Gui_Test.h"
using namespace std;
using namespace ImGui;
#include "MainGame.h"

Gui_Test::Gui_Test(MainGame& gameConstruct)
{
	show_planet_window = false;
	game = gameConstruct;
}

void Gui_Test::CreateStuff()
{

	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	static float f = 0.0f;
	static int counter = 0;

	Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

	//Number of planets
	char tempString[50];
	string tempString2 = "The number of planets is: " + to_string(game.planets.size());
	char* tempChar = new char[tempString2.length()];
	//strcpy_s(tempChar, tempString2.c_str());
	//sprintf_s(tempString, "The number of planets is: ", game.planets.size());
	//const char *tempVar = "The number of planets is: ";// game.planets.size();
	//tempVar
	//Text("The number of planets is: %d", game.planets.size());               // Display some text (you can use a format strings too)
	Text(tempString2.c_str());

	for (int i = 0; i < game.planets.size(); i++) {
		string tempPlanetString = "Planet: " + *game.planets.at(i)->name;
		Text(tempPlanetString.c_str());
	}

	//Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
	Checkbox("Planet Window", &show_planet_window);

	SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
	ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

	if (Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
		counter++;
	SameLine();
	Text("counter = %d", counter);

	End();


	// 3. Show another simple window.
	if (show_planet_window) {
		ImGui::SetNextWindowSize(ImVec2(500, 440), ImGuiCond_FirstUseEver);
		Begin("Planet Overview", &show_planet_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)

		// Left
		static int selected = 0;
		{
			ImGui::BeginChild("left pane", ImVec2(150, 0), true);
			for (int i = 0; i < game.planets.size(); i++) {
				// FIXME: Good candidate to use ImGuiSelectableFlags_SelectOnNav
				if (ImGui::Selectable((*game.planets.at(i)->name).c_str(), selected == i))
					selected = i;
			}
			ImGui::EndChild();
		}
		ImGui::SameLine();

		// Right
		{
			ImGui::BeginGroup();
			ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing())); // Leave room for 1 line below us
			ImGui::Text((*game.planets.at(selected)->name).c_str(), selected);
			ImGui::Separator();
			if (ImGui::BeginTabBar("##Tabs", ImGuiTabBarFlags_None))
			{
				if (ImGui::BeginTabItem("Description"))
				{
					ImGui::TextWrapped("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. ");
					ImGui::EndTabItem();
				}
				if (ImGui::BeginTabItem("Resources"))
				{
					//table
					static ImGuiTableFlags flags = ImGuiTableFlags_SizingStretchSame | ImGuiTableFlags_Resizable | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV | ImGuiTableFlags_ContextMenuInBody;
					PopStyleCompact();

					if (ImGui::BeginTable("table1", 3, flags)) {

						for (size_t row = 0; row < game.planets.at(selected)->resources.size(); row++)
						{
							ImGui::TableNextRow();
							for (int column = 0; column < 3; column++)
							{
								ImGui::TableSetColumnIndex(column);
								if (column == 0) {
									ImGui::Text((*game.planets.at(selected)->resources.at(row)->name).c_str());
								}
								else if (column == 1) {
									ImGui::Text(to_string(*game.planets.at(selected)->resources.at(row)->amount).c_str());
								}
								else if (column == 2) {
									ImGui::Text(to_string(*game.planets.at(selected)->resources.at(row)->hardness).c_str());
								}
							}
						}
						ImGui::EndTable();
					}

					ImGui::Text("ID: 0123456789");
					ImGui::EndTabItem();
				}
				ImGui::EndTabBar();
			}
			ImGui::EndChild();
			if (ImGui::Button("Revert")) {}
			ImGui::SameLine();
			if (ImGui::Button("Save")) {}
			ImGui::EndGroup();
		}


		if (Button("Close Me")) {
			show_planet_window = false;
		}
		End();
	}



	//Main/top menu stuff

	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("New", "CTRL+N")) {}
			if (ImGui::MenuItem("Open", "CTRL+O")) {}
			if (ImGui::MenuItem("Save", "CTRL+S")) {}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Edit"))
		{
			if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
			if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
			ImGui::Separator();
			if (ImGui::MenuItem("Cut", "CTRL+X")) {}
			if (ImGui::MenuItem("Copy", "CTRL+C")) {}
			if (ImGui::MenuItem("Paste", "CTRL+V")) {}
			ImGui::EndMenu();
		}
		
		if (ImGui::BeginMenu("FPS/UPS Menu")) {
			/*
			Ideas for FPS/UPS Window:
			Not resizable
			Has an x button
			Slider for UPS with input that updates based on slider (but will also accept new custom inputs?)
			Graph showing UPS history?
			ImGuiSliderFlags_AlwaysClamp
			Current FPS, from Hello World window
			*/
			ImGui::MenuItem("Show Current FPS/UPS", NULL, &show_UPS_FPS);

			if (ImGui::BeginMenu("Modify UPS"))
			{
				//Modify these to call a method in here, as well as making sure they don't change the game object if it's being modified by the update method
				if (ImGui::MenuItem("1 UPS")) { game.updateTime->SetUpdateTime(1e9 / 1); }
				if (ImGui::MenuItem("10 UPS")) { game.updateTime->SetUpdateTime(1e9 / 10); }
				if (ImGui::MenuItem("50 UPS")) { game.updateTime->SetUpdateTime(1e9 / 50); }
				if (ImGui::MenuItem("60 UPS")) { game.updateTime->SetUpdateTime(1e9 / 60); }
				if (ImGui::MenuItem("100 UPS")) { game.updateTime->SetUpdateTime(1e9 / 100); }
				if (ImGui::MenuItem("250 UPS")) { game.updateTime->SetUpdateTime(1e9 / 250); }
				if (ImGui::MenuItem("500 UPS")) { game.updateTime->SetUpdateTime(1e9 / 500); }
				if (ImGui::MenuItem("750 UPS")) { game.updateTime->SetUpdateTime(1e9 / 750); }
				if (ImGui::MenuItem("1000 UPS")) { game.updateTime->SetUpdateTime(1e9 / 1000); }
				if (ImGui::MenuItem("No Limit")) {} //TODO: Implement
				if (ImGui::MenuItem("Custom")) {} //TODO: Implement
				ImGui::EndMenu();
			}

			ImGui::EndMenu();
		}

		ImGui::EndMainMenuBar();

	}
	if (show_UPS_FPS) {
		UPSWindow();
	}
}

void Gui_Test::PopStyleCompact()
{
	//Temporary solution, the next 3 lines should end up by themselves somewhere
	ImGuiStyle& style = ImGui::GetStyle();
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(style.FramePadding.x, (float)(int)(style.FramePadding.y * 0.60f)));
	ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(style.ItemSpacing.x, (float)(int)(style.ItemSpacing.y * 0.60f)));

	ImGui::PopStyleVar(2);
}

void Gui_Test::UPSWindow() {

	ImGuiWindowFlags window_flags= ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoMove;

	ImGui::SetNextWindowBgAlpha(0.35f); // Transparent background

	//Sets the location
	const float PAD = 10.0f;
	const ImGuiViewport* viewport = ImGui::GetMainViewport();
	ImVec2 work_pos = viewport->WorkPos; // Use work area to avoid menu-bar/task-bar, if any!
	ImVec2 work_size = viewport->WorkSize;
	ImVec2 window_pos, window_pos_pivot;
	window_pos.x = work_pos.x + work_size.x - PAD;
	window_pos.y = work_pos.y + PAD;
	window_pos_pivot.x = 1.0f;
	window_pos_pivot.y = 0.0f;
	ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always, window_pos_pivot);

	Begin("FPS/UPS Overview", &show_UPS_FPS, window_flags);

	string UPSString = "UPS: " + to_string(1e9 / (game.updateTime->GetUpdateTime()))+ ". Updates happen in: "+ to_string(game.updateTime->GetActualUpdateTime())+"ns";
	//Normally for UPS, it'd update time/second, but this only works this way (as this is the time for one update to happen).
	Text(UPSString.c_str());

	Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / GetIO().Framerate, GetIO().Framerate);

	End();
}
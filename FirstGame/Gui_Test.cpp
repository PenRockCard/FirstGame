#include "Gui_Test.h"
using namespace std;
using namespace ImGui;
#include "MainGame.h"

Gui_Test::Gui_Test()
{
    show_planet_window = false;
}

void Gui_Test::CreateStuff(MainGame &game)
{


    cout << *game.planets.at(0)->resources.at(0)->amount << endl;
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

        Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / GetIO().Framerate, GetIO().Framerate);

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
                    if (ImGui::BeginTabItem("Details"))
                    {
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

}

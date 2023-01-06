#include "Gui_Test.h"
using namespace std;
using namespace ImGui;
#include "MainGame.h"

Gui_Test::Gui_Test()
{
    show_another_window = false;
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
        Checkbox("Another Window", &show_another_window);

        SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
        ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

        if (Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
            counter++;
        SameLine();
        Text("counter = %d", counter);

        Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / GetIO().Framerate, GetIO().Framerate);
        End();
    

    // 3. Show another simple window.
        if (show_another_window) {
            Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            Text("Hello from another window!");
            if (Button("Close Me")) {
                show_another_window = false;
            }
            End();
        }

}

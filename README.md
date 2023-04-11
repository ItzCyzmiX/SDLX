# SDLX

## A simpler version of the famous SDL library

Example Code (creating a window):
```
int main(int argc, char** argv)
{
  Window win("SDLX GAME!!", 600, 600);

  bool run = true;

  Event e;

  while(run)
  {
    while(e.checkEvents)
    {
      if (e.quit)
      {
        run = false;
        break;
      }
    }

     win.beginDrawing();

     win.endDrawing();  
  }

  win.quit()
  
  return 0;
}
```
## Download:
### Windows:
* Setup the enviroment:
  * go to the official [github repo](https://github.com/CyzmiX/SDLX.github.io) and download the latest realese of the library
  * create a folder anywhere you want on you computer
  * extract the downloaded realese of the library on it
  * DONE!
* Build your game:
  * to test if you installed SDLX correctly, create a __main.cpp__ file inside the __src__ folder then copy and paste the above code to it
  * open a terminal on the folder where you installed SDLX and type either __make__ to just build the game or __make build_run__ to build and run the game
  * DONE! 

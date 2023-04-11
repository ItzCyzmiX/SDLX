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
go to the official github repo and download the latest realese of the library

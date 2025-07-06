/*
'strcat': This function or variable may be unsafe. Consider using strcat_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.
*/
#define _CRT_SECURE_NO_WARNINGS


#include <cstring>
#include <cstdio>
#include <random>
#include <Windows.h>
namespace Sound
{
    const char* remove = "Windows Hardware Remove.wav";
    const char* insert = "Windows Hardware Insert.wav";
    //USB Device Not Recognized
    const char* unrecognized="Windows Notify System Generic.wav";
}
static std::random_device fromRandomDevice;
void hideConsole()
{
    HWND hwnd;
    hwnd = GetForegroundWindow();
    if (hwnd)
    {
        ShowWindow(hwnd, SW_HIDE);
    }
    else
    {
        std::printf("-1");
    }
}
int main()
{

    hideConsole();


    std::mt19937 bymt19937Generator(fromRandomDevice());
    std::uniform_int_distribution<unsigned> distribute(1,600);// 1s~10min
    std::uniform_int_distribution<unsigned> playTimes(1, 3);
    std::uniform_int_distribution<unsigned> playInsertSound(0, 1);

    char path[MAX_PATH];

    char windowsHardwareRemoveSound[MAX_PATH];
    char windowsHardwareInsertSound[MAX_PATH];
    char windowsNotifySystemGeneric[MAX_PATH];

    int success = GetWindowsDirectoryA(path, MAX_PATH);
    if (!success)
    {
        std::printf("Isn't this program running on Windows?");
        return -1;
    }

    std::strcat(path, "\\Media\\");
    std::sprintf(windowsHardwareRemoveSound,"%s%s",path,Sound::remove);
    std::sprintf(windowsHardwareInsertSound, "%s%s", path, Sound::insert);
    std::sprintf(windowsNotifySystemGeneric, "%s%s", path, Sound::unrecognized);
    

    //std::printf("%s\n", windowsHardwareRemoveSound);
    //std::printf("%s\n", windowsHardwareInsertSound);
    //std::printf("%s\n", windowsNotifySystemGeneric);

    //PlaySoundA(windowsHardwareInsertSound, NULL, SND_FILENAME);
    //PlaySoundA(windowsNotifySystemGeneric, NULL, SND_FILENAME);
    //PlaySoundA(windowsHardwareRemoveSound, NULL, SND_FILENAME);


    while(true)
    {
        int repeat = playTimes(bymt19937Generator);
        for(int i=0;i<repeat;++i)
        {
            PlaySoundA(windowsHardwareRemoveSound, NULL, SND_FILENAME);
        }
        
        
        if(playInsertSound(bymt19937Generator))
        {
            Sleep(1000);
            PlaySoundA(windowsHardwareInsertSound, NULL, SND_FILENAME);
            PlaySoundA(windowsNotifySystemGeneric, NULL, SND_FILENAME);

        }
        Sleep(distribute(bymt19937Generator) * 1000);
    }
}
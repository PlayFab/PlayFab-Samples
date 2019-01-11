using System;
using System.Collections.Generic;
using System.Threading;

class Program
{
    public static LobbyManager g_LobbyManager = new LobbyManager();
    public static PlayerManager g_PlayerManager = new PlayerManager();
    static WebServer g_WebServer = new WebServer();

    public static SemaphoreSlim g_DevelopmentServersMutex = new SemaphoreSlim(1);
    public static List<DevelopmentServer> g_lstDevelopmentServers = new List<DevelopmentServer>();

    public static bool g_bExitRequested = false;

    static async void Tick()
    {
        g_WebServer.Update();
        await MatchmakingManager.Update();
        System.Threading.Thread.Sleep(1);
    }

    static void Main(string[] args)
    {
        Console.WriteLine(@" _____ _____ _____ _____ ____  _____ _____    _____ _____ _____ _____ __    _____ ");
        Console.WriteLine(@"|_   _|  |  |  |  |   | |    \|   __| __  |  | __  |  |  |     | __  |  |  |   __|");
        Console.WriteLine(@"  | | |     |  |  | | | |  |  |   __|    -|  |    -|  |  | | | | __ -|  |__|   __|");
        Console.WriteLine(@"  |_| |__|__|_____|_|___|____/|_____|__|__|  |__|__|_____|_|_|_|_____|_____|_____|");
        Console.WriteLine(@"                                   Lobby Service                                  ");

        if (!g_WebServer.Init())
        {
            GotoExit();
        }

        g_WebServer.Run();

        while (!g_bExitRequested)
        {
            Tick();
        }

        GotoExit();
    }

    private static void GotoExit()
    {
        Console.WriteLine("Press any key to exit...");
        Console.ReadKey(true);
        Environment.Exit(0);
    }
}
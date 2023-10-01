using LedCSharp;

namespace LightSync
{
    public class Program
    {
        static void Main(string[] args)
        {
            // Initialize the LED SDK
            bool LedInitialized = LogitechGSDK.LogiLedInitWithName("SetTargetZone Sample C#");

            if (!LedInitialized)
            {
                Console.WriteLine("LogitechGSDK.LogiLedInit() failed.");
                return;
            }

            Console.WriteLine("LED SDK Initialized");

            LogitechGSDK.LogiLedSetTargetDevice(LogitechGSDK.LOGI_DEVICETYPE_ALL);

            // Set all devices to Black
            //LogitechGSDK.LogiLedSetLighting(0, 0, 0);

            // Controls individual light zone for given device
            LogitechGSDK.LogiLedSetLightingForTargetZone(DeviceType.Mouse, 0, 0, 0, 100);
            LogitechGSDK.LogiLedSetLightingForTargetZone(DeviceType.Mouse, 1, 0, 0, 100);

            Console.WriteLine("Press \"ENTER\" to continue...");
            Console.ReadLine();

            Console.WriteLine("LED SDK Shutting down");
            LogitechGSDK.LogiLedShutdown();
        }
    }
}

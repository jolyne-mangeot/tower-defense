using System.Runtime.InteropServices;
using UnityEngine;

public class PluginTest : MonoBehaviour
{
    [DllImport("libTest")]
    private static extern int Multiply(int a, int b);

    void Start()
    {
        int result = Multiply(2, 3);
        Debug.Log("2 * 3 = " + result);
    }
}
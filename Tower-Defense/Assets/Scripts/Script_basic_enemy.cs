using System;
using System.Runtime.InteropServices;
using UnityEngine;

public class EnemyWrapper : MonoBehaviour
{
    [DllImport("plugin-unity")]
    private static extern IntPtr CreateEnemy(int hp, float speed, int reward);

    [DllImport("plugin-unity")]
    private static extern void DestroyEnemy(IntPtr enemy);

    [DllImport("plugin-unity")]
    private static extern void EnemyMove(IntPtr enemy);

    private IntPtr enemyInstance;

    void Start()
        {
            try
        {
            Debug.Log("Création de l’ennemi...");
            enemyInstance = CreateEnemy(100, 2.0f, 50);
            Debug.Log("Créé !");
            EnemyMove(enemyInstance);
        }
        catch (Exception e)
        {
            Debug.LogError("Erreur pendant le chargement de la DLL : " + e.Message);
        }
    }

    void OnDestroy()
    {
        if (enemyInstance != IntPtr.Zero)
            DestroyEnemy(enemyInstance);
    }
}

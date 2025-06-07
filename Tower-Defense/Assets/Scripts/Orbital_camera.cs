using UnityEngine;

public class Orbital_camera : MonoBehaviour
{
    public Transform target; // Le centre de la carte
    public float distance = 70.0f; // Distance de la caméra au centre
    public float zoomSpeed = 6000f;
    public float rotationSpeed = 8f;
    private float targetDistance;
    public float minY = 10f;  // Angle vertical minimum
    public float maxY = 80f;  // Angle vertical maximum

    private float currentX = 45f;
    private float currentY = 45f; // Angle initial vertical

    void Start()
    {
        targetDistance = distance;
    }

    void LateUpdate()
    {
        if (Input.GetMouseButton(1)) // Clic droit pour tourner
        {
            currentX += Input.GetAxis("Mouse X") * rotationSpeed;
            currentY -= Input.GetAxis("Mouse Y") * rotationSpeed;
            currentY = Mathf.Clamp(currentY, minY, maxY);
        }

        targetDistance -= Input.GetAxis("Mouse ScrollWheel") * zoomSpeed * 7f;  // Multiplie par 5 ou 10
        targetDistance = Mathf.Clamp(targetDistance, 45f, 125f);
        distance = Mathf.Lerp(distance, targetDistance, Time.deltaTime * 5f);

        Quaternion rotation = Quaternion.Euler(currentY, currentX, 0);
        Vector3 direction = new Vector3(0, 0, -distance);

        if (target != null)
        {
            transform.position = target.position + rotation * direction;
            transform.LookAt(target.position);
        }
    }
}
using UnityEngine;

public class Stand : Timer {

    private Quaternion rotY;

    public GameObject car;

   protected override void timerDo()
    {
        rotY = Quaternion.AngleAxis(1, Vector3.up);
        transform.rotation *= rotY;
        StartTimer(0.05F);
    }
}

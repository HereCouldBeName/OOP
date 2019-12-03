using UnityEngine;

public class PlayerMotor : Motor {

    private bool haveGas;

    private void Start() {
        lastAcceleration = acceleration;
        speedRpmRecession = 2 * speedRpm;
        turn = 0;
        resetTurn = 3000;

        numberOfZone = 3;
        zoneturn = new ZoneTurn[numberOfZone];
        ZoneTurn tmp;
        tmp.begin = 0f;
        tmp.end = 5999f;
        tmp.acceleration = acceleration / 3;
        zoneturn[0] = tmp;
        tmp.begin = 6000f;
        tmp.end = 6499f;
        tmp.acceleration = acceleration;
        zoneturn[1] = tmp;
        tmp.begin = 6500f;
        tmp.end = 9000f;
        tmp.acceleration = acceleration / 5;
        zoneturn[2] = tmp;
    }
    private void FixedUpdate() {
        if (!haveGas) {
            if (turn > 0) {
                turn -= speedRpmRecession;
            }
        }
        haveGas = false;
    }

    public override void Work() {
        haveGas = true;
        turn += speedRpm;
        if (turn > 9000) {
            Debug.Log("CAR is BROKEN");
        }
    }
}

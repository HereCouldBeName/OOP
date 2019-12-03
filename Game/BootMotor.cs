using UnityEngine;

public class BootMotor : Motor {
    private void Start() {
        lastAcceleration = acceleration;
        speedRpmRecession = 2 * speedRpm;
        turn = 0;
        resetTurn = 3000;

        numberOfZone = 2;
        zoneturn = new ZoneTurn[numberOfZone];
        ZoneTurn tmp;
        tmp.begin = 0f;
        tmp.end = 5999f;
        tmp.acceleration = acceleration /3;
        zoneturn[0] = tmp;
        tmp.begin = 6000f;
        tmp.end = 6499f;
        tmp.acceleration = acceleration;
        zoneturn[1] = tmp;
    }
    public override void Work() {
        turn += speedRpm;
        float rand = Random.Range(zoneturn[0].end - 30f, zoneturn[1].begin+30f);
        if(turn >= rand) {
            ShiftGear();
        }
    }
}

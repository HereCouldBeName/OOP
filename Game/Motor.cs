using UnityEngine;
public abstract class Motor : Timer {

    protected struct ZoneTurn {
        public float acceleration;
        public float begin, end;
    }

    protected float turn;
    protected float resetTurn;
    protected float speedRpmRecession;
    protected float lastAcceleration;

    [SerializeField] protected float speedRpm;
    [SerializeField] protected float acceleration;

    protected ZoneTurn[] zoneturn;
    protected int numberOfZone;

    public float GetTurn() {
        return turn;
    }

    protected override void timerDo() {
        acceleration = lastAcceleration;
    }

    public float GetAcceleration() {
        return acceleration;
    }

    public virtual void Work() { }

    public void ShiftGear() {
        if (!GetTimerStatus()) {
            speedRpm += 2;
            for (int i = 0; i < numberOfZone; i++) {
                if (turn >= zoneturn[i].begin && turn <= zoneturn[i].end) {
                    lastAcceleration = acceleration;
                    acceleration = zoneturn[i].acceleration;
                    StartTimer(0.5F);
                    break;
                }
            }
            turn -= resetTurn;
        }
    }
}

using UnityEngine;

public class Car : MonoBehaviour {

    [SerializeField] protected Detal[] whell;
    [SerializeField] protected Detal frontBumper;
    [SerializeField] protected Detal backBumper;
    [SerializeField] protected Detal spoiler;
    [SerializeField] protected Detal[] skirt;
    [SerializeField] protected Motor engine;

    private Rigidbody rb;

    private float speed;

    public float GetSpeed() {
        return speed;
    }

    public Detal[] GetWheel() {
        return whell;
    }

    public void Move() {
        engine.Work();
        rb.AddForce(0, 0, engine.GetAcceleration(), ForceMode.Acceleration);
        for (int i = 0; i < 4; i++) {
            whell[i].transform.Rotate(-speed * 10 * Time.deltaTime, 0, 0);
        }
    }
    public float GetTurnEngine() {
        return engine.GetTurn();
    }

    public void ShiftGearEngine() {
        engine.ShiftGear();
    }

    private void Start() {
        rb = GetComponent<Rigidbody>();
    }

    private void Update() {
        speed = Mathf.Round(rb.velocity.magnitude * 2);
    }

    public void Tuning(string s, int type) {
        switch (type) {
        case 0:
            if(frontBumper != null) {
                Destroy(frontBumper.gameObject);
            }
            if(s.Length > 0) {
                frontBumper = SetNewItem(s)[0];
            }
            break;
        case 1:
            if(backBumper != null) {
                Destroy(backBumper.gameObject);
            }
            if(s.Length > 0) {
                backBumper = SetNewItem(s)[0];
            }
            break;
        case 2:
            for(int i=0; i<4; i++) {
                Destroy(whell[i].gameObject);
            }
            whell = SetNewItem(s);
            break;
        case 3:
            if(spoiler != null) {
                Destroy(spoiler.gameObject);
            }
            if(s.Length > 0) {
                spoiler = SetNewItem(s)[0];
            }
            break;
        case 4:
            if (skirt.Length != 0) {
                for (int i = 0; i < 2; i++) {
                    Destroy(skirt[i].gameObject);
                }
                skirt = new Detal[0];
            }
            if(s.Length > 0) {
                skirt = SetNewItem(s);
            }
            break;
        }
    }
    private Detal[] SetNewItem(string s) {
        GameObject obj = Instantiate(Resources.Load(s)) as GameObject;
        Detal detal = obj.GetComponent("Detal") as Detal;
        int l = detal.CountOfObject();
        Vector3[] pos = detal.GetPos();
        Vector3[] rot = detal.GetRot();
        Vector3 scale = detal.GetScale();
        Detal[] objDetal = new Detal[l];
        for (int i = 0; i < l; i++) {
            obj.transform.SetParent(this.transform);
            obj.transform.localPosition = pos[i];
            obj.transform.localRotation = Quaternion.Euler(rot[i]);
            obj.transform.localScale = scale;
            objDetal[i] = obj.GetComponent("Detal") as Detal;
            if(i < l-1) {
                obj = Instantiate(Resources.Load(s)) as GameObject;
            }
        }
        return objDetal;
    }
}

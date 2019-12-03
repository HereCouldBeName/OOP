using UnityEngine;

public class Detal : MonoBehaviour {
    [SerializeField] protected Vector3[] pos, rot;
    [SerializeField] protected Vector3 scale;
    [SerializeField] protected GameObject obj { get; set; }

    public Vector3[] GetPos() {
        return pos;
    }

    public int CountOfObject() {
        return pos.Length;
    }

    public Vector3[] GetRot() {
        return rot;
    }

    public Vector3 GetScale() {
        return scale;
    }
}

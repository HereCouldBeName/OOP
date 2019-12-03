using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Taxometr : MonoBehaviour {

    private RectTransform arrow;
    private float start;
    private float k;

    void Start () {
        arrow = GetComponent<RectTransform>();
        arrow.localRotation = Quaternion.Euler(0, 0, start);
        start = 135.7F;
        k = 0.03f;
    }

	public void SetPosArrow(float turn) {
        float turnArrow = start - k * turn;
        arrow.localRotation = Quaternion.Euler(0, 0, turnArrow);
    }
    
}

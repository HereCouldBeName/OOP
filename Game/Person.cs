﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class Person : MonoBehaviour {

    protected bool IsGameStart = false;

    public void StartRace() {
        IsGameStart = true;
    }

}

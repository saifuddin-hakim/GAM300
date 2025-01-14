﻿/*!*************************************************************************
****
\file FPS_Controller_Script.cs
\author Elton Teo
\par DP email: e.teo@digipen.edu
\par Course: csd3450
\date 10-2-2024
\brief  Script for controlling movement of player
****************************************************************************
***/
using System;
using ScriptAPI;

public enum GameState { Intro, LockpickTutorial, Gameplay, Event1, Event2, Event3, Event4 }
public class CheckGameState : Script
{
    public GameState _CurrentState;
    public GameDataManager myGameDataManager;

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

    }
}

﻿using System;
using ScriptAPI;

public class MilestoneScript : Script
{
    public GameObject bedroomLights;
    public GameObject monster;
    public GameObject bedroomDoor;
    public GameObject painting;
    public GameObject closet;
    public float timer;
    public float scriptEventtimer;
    public AudioComponent voClip;
    String[] soundEffectstring;
    public static int counter;
    public static bool next;

    public override void Awake()
    {
        timer = 0.0f;
        scriptEventtimer = 0.0f;
        voClip = gameObject.GetComponent<AudioComponent>();
        soundEffectstring = new String[4];
        counter = 2;
        next = true;
    }

    public override void Start()
    {
        soundEffectstring[0] = "pc_monsterrattledoor";
        soundEffectstring[1] = "Heartbeating_Sound";
        bedroomLights = GameObjectScriptFind("BedroomLight");
        monster = GameObjectScriptFind("Monster");
        bedroomDoor = GameObjectScriptFind("Bedroom Double Door");
        painting = GameObjectScriptFind("Frame");
        closet = GameObjectScriptFind("Body2");
    }

    public override void Update()
    {
        if (!painting.ActiveInHierarchy() && scriptEventtimer < 12.0f)
        {
            voClip.play(soundEffectstring[0]);
            bedroomLights.GetComponent<BlinkingLights>().is_Enabled = true;
            bedroomDoor.SetActive(true);
            scriptEventtimer += Time.deltaTime;
            if (closet.GetComponent<Hiding>().hiding)
            {
                voClip.play(soundEffectstring[1]);
                monster.SetActive(true);
                timer += Time.deltaTime;
                Vector3 vec = monster.transform.GetPosition();
                vec.X += 15.0f * Time.deltaTime;
                vec.Z += 15.0f * Time.deltaTime;
                monster.transform.SetPosition(vec);

                if (!closet.GetComponent<Hiding>().hiding)
                {
                    monster.GetComponent<GhostMovement>().is_Enabled = true;
                }

                if (timer > 2.0f)
                {
                    monster.SetActive(false);
                    timer = 0.0f;
                }
            }
        }
        if (scriptEventtimer > 12.0f)
        {
            monster.SetActive(false);
            voClip.playQueue();
            if (counter < 4)
            {
                if (next)
                {
                    voClip.play(soundEffectstring[counter]);
                    next = false;
                }
                else if (voClip.finished(soundEffectstring[counter]))
                {
                    next = true;
                    ++counter;
                }
            }
        }

        if (scriptEventtimer > 15.0f)
        {
            monster.SetActive(true);
            voClip.play(soundEffectstring[1]);
        }

        if (scriptEventtimer > 16.0f)
        {
            monster.SetActive(false);
        }
    }
}

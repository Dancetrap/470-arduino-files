using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class SerialManager : MonoBehaviour
{
    public string sPort = "COM6";
    [HideInInspector]
    public SerialPort sp;
    [HideInInspector]
    public bool noBytes;
    [HideInInspector]
    public int pastByte = 0;

    bool constant = true;
    bool on = false;
    bool wait = false;
    bool lerp = false;

    public AudioSource playBack;
    public Light[] lights;
    public Material[] emissions;
    public ParticleSystem[] systems;

    public float intensity = 1;
    public float duration = 1;

    float t = 0;

    float counter = 0;

    // Start is called before the first frame update
    void Start()
    {
        sp = new SerialPort(sPort, 9600);
        sp.Open();

        lights = FindObjectsOfType<Light>();
        systems = FindObjectsOfType<ParticleSystem>();
        audioPlayer(false);
        lightSwitch(false);
    }

    // Update is called once per frame
    void Update()
    {
        //counter += 1;
        //print(counter);
        if (sp.IsOpen)
        {
//            print(pastByte == sp.BytesToRead);
            constant = pastByte == sp.BytesToRead;
            if(!constant && !wait)
            {
                counter += 1;
                if(!on /* && counter == 1*/)
                {
                    on = !on;
                    wait = true;
                    StartCoroutine(timeout());
                    counter = 0;
                }
                else if(on /* && counter == 2*/)
                {
                    on = !on;
                    wait = true;
                    StartCoroutine(timeout());
                    counter = 0;
                }
            }

            //audioPlayer(on);
            lightSwitch(on);


            pastByte = sp.BytesToRead;
        }
    }

    public void lightSwitch(bool o)
    {
        if (o)
        {
            lerp = true;
            for (int i = 0; i < lights.Length; i++)
            {
                if (lights[i].name != "Direction Light" && lights[i].name != "Burn") lights[i].enabled = true;
                //if (lights[i].name == "Burn") lights[i].intensity = Mathf.Lerp(0, intensity, t);
            }
            for (int i = 0; i < emissions.Length; i++)
            {
                emissions[i].EnableKeyword("_EMISSION");
            }
            for (int i = 0; i < systems.Length; i++)
            {
                systems[i].Play();
            }
        }
        else
        {
            lerp = false;
            for (int i = 0; i < lights.Length; i++)
            {
                if (lights[i].name != "Direction Light" && lights[i].name != "Burn") lights[i].enabled = false;
                //if (lights[i].name == "Burn") lights[i].intensity = Mathf.Lerp(intensity, 0, t);
            }
            for (int i = 0; i < emissions.Length; i++)
            {
                emissions[i].DisableKeyword("_EMISSION");
            }
            for (int i = 0; i < systems.Length; i++)
            {
                systems[i].Stop();
            }
        }

        t += duration / Time.deltaTime;

        if (lerp)
            GameObject.Find("Burn").GetComponent<Light>().intensity = Mathf.Lerp(GameObject.Find("Burn").GetComponent<Light>().intensity, intensity, Time.deltaTime / 0.5f);
        else
            GameObject.Find("Burn").GetComponent<Light>().intensity = Mathf.Lerp(GameObject.Find("Burn").GetComponent<Light>().intensity, 0, Time.deltaTime / 0.5f);
    }

    public void audioPlayer(bool o)
    {
        if(playBack != null)
        {
            if(o)
            {
                playBack.UnPause();
            }
            else
            {
                playBack.Pause();
            }
        }
    }

    public IEnumerator timeout()
    {
        yield return new WaitForSecondsRealtime(0.5f);
        wait = false;
    }
}
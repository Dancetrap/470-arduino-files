using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
using UnityEngine.UI;

public class SerialSystem : MonoBehaviour
{
    public string sPort = "COM6";
    [HideInInspector]
    public SerialPort sp;
    public GameObject warningScreen;
    public Text message;
    [HideInInspector]
    public bool noBytes;
    // Start is called before the first frame update
    void Start()
    {
        warningScreen.SetActive(false);
        sp = new SerialPort(sPort, 9600);
        sp.Open();
    }

    // Update is called once per frame
    void Update()
    {
        if(!sp.IsOpen)
        {
            warningScreen.SetActive(true);
            message.text = "Warning:\nYou appear to not be connected to Nano 33 Iot.\nPlease close out of the application,\nconnect Nano 33 Iot to device,\nopen arduino.exe and upload 'Gyro' before reopening application";
        }
        else
        {
            //Debug.Log(sp.BytesToRead);
/*            if(noBytes)
            {
                warningScreen.SetActive(true);
                message.text = "Warning:\nIt appears there is something\nwrong with your 'Gyro' script.\nPlease open arduino to fix it from there.";
                Debug.LogError("No bytes avaiable");
            }*/
        }
    }
}

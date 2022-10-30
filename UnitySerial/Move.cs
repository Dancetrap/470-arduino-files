using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
using UnityEngine.UI;

public class Move : MonoBehaviour
{
    //    public string sPort = "COM6";
    //    SerialPort sp;
    SerialSystem sp;
    Vector3 cameraPosition;
    Vector2 halfCameraSize = Vector2.zero;
    GameManager manager;
//    public GameObject warningScreen;
//    public Text message;
    // Start is called before the first frame update
    void Start()
    {
        manager = FindObjectOfType<GameManager>();
        //warningScreen.SetActive(false);
        cameraPosition = Camera.main.transform.position;
        halfCameraSize.y = Camera.main.orthographicSize;
        halfCameraSize.x = halfCameraSize.y * Camera.main.aspect;
        sp = FindObjectOfType<SerialSystem>();
//        sp = new SerialPort(sPort, 9600);
//        sp.Open();
        //        sp.ReadTimeout = 5000;
        //        sp.DtrEnable = true;
    }

    // Update is called once per frame
    void Update()
    {
        Debug.Log(sp.noBytes);
        //Debug.Log(sp.sp.BytesToRead);
        if (manager.isGameOver)
        {
            Destroy(this.gameObject);
        }

        if(sp.sp.IsOpen && sp.sp.BytesToRead == 0)
        {
            //sp.noBytes = true;
            StartCoroutine(setNoBytes());
        }
        else
        {
            StopCoroutine(setNoBytes());
            sp.noBytes = false;
        }

        if (sp.sp.IsOpen && sp.sp.BytesToRead != 0 && !manager.isGameOver){
            try
            {
                //Debug.Log(sp.sp.BytesToRead);
                if(sp.sp.ReadByte() < 255 && sp.sp.ReadByte() >= 160)
                {
                    transform.Rotate(0, 0, -1f);
                }
                else if(sp.sp.ReadByte() > 0 && sp.sp.ReadByte() <= 90)
                {
                    transform.Rotate(0, 0, 1f);
                }
                sp.sp.ReadExisting();
            }
            catch (System.Exception e){
                Debug.LogError(e.ToString());
                //warningScreen.SetActive(true);
            }

            if (transform.rotation.z <= 0)
            {
                if (transform.position.x < cameraPosition.x + halfCameraSize.x)
                {
                    transform.Translate(new Vector3(transform.rotation.z / -10, 0, 0), Space.World);
                }
            }
            else if (transform.rotation.z > 0)
            {
                if (transform.position.x > cameraPosition.x - halfCameraSize.x)
                {
                    transform.Translate(new Vector3(transform.rotation.z / -10, 0, 0), Space.World);
                }
            }
        }
        else
        {
/*            try
            {
                Debug.Log("Null");
            }
            catch(System.Exception e)
            {*/
                //warningScreen.SetActive(true);
                //message.text = "Warning:\nYou appear to not be connected to Nano 33 Iot.\nPlease close out of the application,\nconnect Nano 33 Iot to device,\nopen arduino.exe and upload 'Gyro' before reopening application";
            //}

        }
    }

    public IEnumerator setNoBytes()
    {
        yield return new WaitForSecondsRealtime(5);
        sp.noBytes = true;
    }
}

package LoggerRateLimiter;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
public class logger {

    Map<Integer,Integer>messageMap;
    logger()
    {
        this.messageMap=new HashMap<>();
    }
    public void printMessage(message message)
    {
        int currTimeStaMP=currTime-message.timeStamp>=10;
        System.out.println(message.message);
    }

}

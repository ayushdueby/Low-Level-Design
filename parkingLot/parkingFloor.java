import java.util.List;
import java.util.Optional;

public class parkingFloor {
    List<parkingSlot> parkingSlotList;
    int floorNumber;

    parkingSlot getFreeSlot(car onboardingCar)
    {
        for(parkingSlot parkingSlot:parkingSlotList)
        {
            if(parkingSlot.canFit(onboardingCar))
            {
                return parkingSlot;
            }
        }
        return null;
    }

    public boolean parkVehicle(car onboardingCar)
    {
        parkingSlot parkingSlot=getFreeSlot(onboardingCar);
        if(parkingSlot!=null)
        {
            parkingSlot.isAvailable=false;
            parkingSlot.car=onboardingCar;
            //update the parkingSlot-->mongoUpdateQuery
            //.update
            return true;
        }
        else
        {
//            not able to park this
            return false;
        }
    }
}


import java.util.Arrays;
import java.util.List;

public class parkingnuilding {

    int id;
    List<parkingFloor> parkingFloorList;

    parkingnuilding(List<parkingFloor>parkingFloorList,car onboardingCar)
    {
        this.parkingFloorList=parkingFloorList;
        parkingFloorList.sort((a, b) -> a.floorNumber - b.floorNumber);
    }

    public String parkVehileInBuilding(car onboardingCar)
    {
        for(parkingFloor floor:parkingFloorList)
        {
            if(floor.parkVehicle(onboardingCar))
            {
                return "Vehicle is parked";
            }
        }
        return "no space atm";
    }
}

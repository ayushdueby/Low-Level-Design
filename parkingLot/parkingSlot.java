public class parkingSlot {
    int id;
    int floor;
    carSize carSize;
    boolean isAvailable;
    car car;

    public boolean canFit(car onboardingCar)
    {
        return isAvailable && onboardingCar.equals(this.carSize);
    }
    public car getParkedCar()
    {
        if(isAvailable==false)return car;
        else return null;
    }
}

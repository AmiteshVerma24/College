# Create a class called CAR, data members ( model_name, color, price, top_speed)
# method: read above details using constructor (__int__) and without constructor.
# Display above detail 
class car:
    def __init__(self, model_name, color, price, top_speed):
        self.model_name = model_name
        self.color = color
        self.price = price
        self.top_speed = top_speed
    def display(self):
        print("Model name: ", self.model_name)
        print("Colour: ", self.color)
        print("Price: ", self.price)
        print("Top speed: ", self.top_speed)
        print("\n")

# With __init__
my_car_1 = car("Apache", "White", 1000, 180)
my_car_1.display()
# Without __init__
my_car_2 = car
my_car_2.model_name = "Nexon"
my_car_2.color = "White"
my_car_2.price = 2000
my_car_2.top_speed = 150
my_car_2.display(my_car_2)


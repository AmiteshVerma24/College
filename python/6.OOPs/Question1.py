# Create a class called CAR, data members ( model_name, color, price, top_speed)
# method: read above details using constructor (__int__) and without constructor.
# Display above detail 
class Car:
    def __init__(self, model_name = "", color = "", price = "", top_speed = ""):
        self.model_name = model_name
        self.color = color
        self.price = price
        self.top_speed = top_speed
    def display(self):
        print("Model: ", self.model_name)
        print("Color: ", self.color)
        print("Price: ", self.price)
        print("Top Speed: ", self.top_speed)
        print()
# With constructor
car1 = Car("Model 1", "Color 1", "Price 1", "Top Speed 1")
# Without constructor
car2 = Car()
car2.model_name = "Model 2"
car2.color = "Color 2"
car2.price = "Price 2"
car2.top_speed = "Top Speed 2"

car1.display()
car2.display()
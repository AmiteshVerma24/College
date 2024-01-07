class bank:
    def __init__(self, bank_name, number_cust):
        self.bank_name = bank_name
        self.number_cust = number_cust

class govt_bank(bank):
    def __init__(self, bank_name, number_cust, branch_name, ifsc_code):
        super().__init__(bank_name, number_cust)
        self.branch_name = branch_name
        self.ifsc_code = ifsc_code
    def display(self):
        print("Bank name: ", self.bank_name)
        print("Number of cust: ", self.number_cust)
        print("Branch name: ", self.branch_name)
        print("IFSC code: ", self.ifsc_code)
        print("\n")
        
class private_bank(bank):
    def __init__(self, bank_name, number_cust, branch_name, ifsc_code):
        super().__init__(bank_name, number_cust)
        self.branch_name = branch_name
        self.ifsc_code = ifsc_code
    def display(self):
        print("Bank name: ", self.bank_name)
        print("Number of cust: ", self.number_cust)
        print("Branch name: ", self.branch_name)
        print("IFSC code: ", self.ifsc_code)
        print("\n")

gov = govt_bank("SBI", 3500, "Peenya", "SBI@123")
pvt = private_bank("Abix bank", 1500, "Hebbal", "AXIS@123")

gov.display()
pvt.display()

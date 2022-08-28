# Emir Asal

def import_inventory():
  my_dictionary = {}
  opened_products = open("products.txt", "r")
  for x in opened_products:
    line = x.lower()
    splitted_list = line.split("-")
    for product in splitted_list:
      index = product.find("_")
      key = product[:index]
      value = int(product[index+1:])
      if key in my_dictionary:
        my_dictionary[key] += value
      else:   
        my_dictionary[key] = value

  opened_products.close()
  return my_dictionary  

def sell_product(products):
  sell_input = input("Please enter products to sell: ")
  sell = sell_input.lower()
  split_sell = sell.split("-")
  for product in split_sell:
    index = product.find("_") 
    key = product[:index]
    value = int(product[index+1:])
    if key in products:
      if value <= products[key]:
        products[key] -= value
        if products[key] == 0:
          products.pop(key)
        print(value, key, "sold.")  
      else:
        print("There is not enough", key, "in inventory.")
    else:
      print(key, "does not exist in inventory.")  

def show_remaining(products):
  if len(products) > 0:  
    alph_products = sorted(products)
    for product in alph_products:
      print(product, ":", products[product])
  else:
    print("Inventory is empty!")

# DO NOT MODIFY THIS CODE CELL, JUST RUN IT

products = import_inventory()
decision = ""
while decision != "3":
  print("*---------------------------")
  print("[1] Sell products")
  print("[2] Show remaining inventory")
  print("[3] Terminate")

  decision = input("Please enter your decision: ")
  print("____________________________")
  if decision == "1":
    sell_product(products)
  elif decision == "2":
    show_remaining(products)
  elif decision == "3":
    print("Terminating...")
  else:
    print("Invalid input!")
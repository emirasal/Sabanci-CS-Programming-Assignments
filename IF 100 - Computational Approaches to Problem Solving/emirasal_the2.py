# Emir Asal

previouscoursegrades = input("Please enter the courses you have taken previously with letter grades: ")
if previouscoursegrades.count(":") != previouscoursegrades.count(";") + 1: 
    print("Invalid input")
else:
    replaced_previous_grades = previouscoursegrades.replace(";", ":")
    splitted_previous_grades =  replaced_previous_grades.split(":")
    currentcoursegrades = input("Please enter the courses you have taken this semester with letter grades: ")
    if currentcoursegrades.count(":") != currentcoursegrades.count(";") + 1:
        print("Invalid input")
    else:
        replaced_current_grades = currentcoursegrades.replace(";", ":")
        splitted_current_grades = replaced_current_grades.split(":")
        course = input("Please enter the course you want to check: ")
        if course in splitted_current_grades:            
            letter_index = splitted_current_grades.index(course) + 1
            letter_grade = splitted_current_grades[letter_index].upper() 
            if letter_grade != "F":
                print("You can choose between S and", letter_grade, "for", course + ".")
            elif letter_grade == "F" and course not in splitted_previous_grades:
                print("Your grade for", course, "is U.")
            elif letter_grade == "F" and course in splitted_previous_grades:
                pre_letter_index = splitted_previous_grades.index(course) + 1
                pre_letter_grade = splitted_previous_grades[pre_letter_index].upper()
                if pre_letter_grade == "U":
                    print("Your grade for", course, "is U.")
                else:
                    print("Your grade for", course, "is F.")    
        else:
          print("You didn't take", course, "this semester.")           
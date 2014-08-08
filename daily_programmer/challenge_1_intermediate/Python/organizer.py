import sys
import datetime

class Event(object):
    " The class that represents one event the user can organize "
    
    def __init__(self, name, description, datetime):
        self.name = name
        self.description = description
        self.datetime = datetime

list_of_events = []

def show_prompt(prompt = '> '):
    print("Enter a choice")
    user_input = int(input(prompt))
    evaluate(user_input)

def evaluate(user_input):
    if user_input == -1:
        print_usage()
        sys.exit(-1)
    elif user_input == 1:
        add_event()
    elif user_input == 2:
        event_name = input("Enter the event's to be deleted name ")
        index = search_event(event_name)
        delete_event(index)
    elif user_input == 3:
        event_name = input("Enter the event's to be edited name ")
        index = search_event(event_name)
        edit_event(index)
    elif user_input == 4:
        view_events()
    elif user_input == 0:
        sys.exit(0) # exiting normally
    else:
        print("Your input was invalid.")
        print("Enter a number from 0 to 4.")
        print("-- Or -1 for help.")

    show_prompt()

def print_usage():
    "Print usage options"
    print("organizer.py v0.1")
    print("Enter 1 in the prompt, to add an event.")
    print("Enter 2 in the prompt, to delete an event.")
    print("Enter 3 in the prompt, to edit an event.")
    print("Enter 4 in the prompt, to view all the events.")
    print("Enter 0 in the prompt, to exit the program.")

def add_event():
    '''Ask user input to create an event, then add
    that event to the list of events.
    '''
    event_name = input("Give a short name for the event. ")
    event_description = input("Give a short description for the event. ")
    
    # Temporary variables to store datetime values
    event_year = int(input("Now please enter the year the event takes place "))
    event_month = int(input("Now please enter the month the event takes place "))
    event_day = int(input("Now please enter the day the event takes place "))
    event_hour = int(input("Now please enter the hour the event takes place "))

    event_datetime = datetime.datetime(event_year, event_month, event_day, event_hour)

    user_event = Event(event_name, event_description, event_datetime)
    list_of_events.append(user_event)

def search_event(name):
    for event in list_of_events:
        if event.name == name:
            return list_of_events.index(event)

def edit_event(index):
    "Edit an event, chosen by index."
    if index is None:
        print("Event not found :(")
        show_prompt()

    event_name = input("Enter the new name ")
    event_description = input("Enter the new description ")
    
    # Temporary variables to store datetime values
    event_year = int(input("Enter the new year "))
    event_month = int(input("Enter the new month "))
    event_day = int(input("Enter the new day "))
    event_hour = int(input("Enter the new hour "))

    event_datetime = datetime.datetime(event_year, event_month, event_day, event_hour)

    list_of_events[index].name = event_name
    list_of_events[index].description = event_description
    list_of_events[index].datetime = event_datetime

def delete_event(index):
    "Delete an event, chosen by index."
    if index is None:
        print("Event not found :(")
        show_prompt()

    del list_of_events[index]

def view_events():
    "View all events in the list"
    for event in list_of_events:
        print("Name: ", event.name)
        print("Description: ", event.description)
        print("Date: ", event.datetime)

if __name__ == "__main__":
    print_usage()
    show_prompt()

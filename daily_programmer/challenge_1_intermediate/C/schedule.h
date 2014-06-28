
typedef struct date {
    int year;
    int month;
    int day;
    int hour;
} date_t;

typedef struct event {
    char *name;
    char *description;
    date_t date;
    struct event *next;
} event_t;

// Display usage string
void help (void);

// Present a user with a prompt, input his choice, then pick
// a relative action based on that choice.
void parse_choice (void);

// Add an event to the list of events.
void add_event (void);


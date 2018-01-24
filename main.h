typedef enum {
        DIR_NORTH = 0,
        DIR_EAST  = 1,
        DIR_SOUTH = 2,
        DIR_WEST  = 3,
} dir_t;

typedef struct {
        int32_t x;
        int32_t y;
        dir_t d;
} rover_t;

typedef enum {
        RESULT_SUCCESS = 0,
        RESULT_UKNOWN = 1,
} command_result_t;

extern command_result_t handle_command(rover_t* rover, char command);


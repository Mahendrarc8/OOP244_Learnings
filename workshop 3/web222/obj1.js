let gameLevel = {
    name: 'Level 1',
    rooms: {
        // Each room has a unique ID
        R31343: {
            name: 'Front Hallway'
        },
        R31344: {
            name: 'Kitchen',
            monster: {
                name: 'Bear',
                strength: 15
            } 
        },
        R31345: {
            name: 'Back Hallway'
        },
        R31346: {
            name: 'Sitting Room',
            monster: {
                name: 'Dog',
                strength: 8
            }
        }
    }
};

console.log(gameLevel.rooms.R31344.monster.strength);


#include "player.h"

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish 
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;

    /* 
     * Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */

    s = side;
    b = new Board();
    cerr << s << endl;
}

/*
 * Destructor for the player.
 */
Player::~Player() {
    delete b;
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be NULL.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return NULL.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    /* 
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */ 

    // Process opponents move
    if (s == BLACK) {
        b->doMove(opponentsMove, WHITE);
    }
    else {
        b->doMove(opponentsMove, BLACK);
    }

    // // Check if we need to pass
    // if (b->checkMove(NULL, s)) {
    //     return NULL;
    // }
    // Compute valid moves
    vector<Move> moves;
    Move *m = new Move(0,0);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            m->x = i;
            m->y = j;
            if (b->checkMove(m, s)) {
                cerr << m->x << m->y << endl;
                moves.push_back(Move(i,j));
            }
        }
    }
    delete m;     
    // Select move
    int randomIndex = rand() % moves.size();
    int x = moves[randomIndex].x;
    int y = moves[randomIndex].y;
    Move *res = new Move(x,y);
    return res;
}

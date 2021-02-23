int main() {
    std::cout << "Hello World!\n";
}
//camel, elephant, queen
// true - white
// false - black
class ChessBoard {
    vector<vector<pair<char, bool>>> board(8, vector<pair<char, bool>>(8, {}));
    
    pair<char, bool> get(int x, int y) {
        return chessBoard[x][y];
    }
    
    unordered_set<Camel> camelList;
    
    bool isInsideChess(int x, int y) {
        return x>=0 && x<8 && y>=0 && y<8;
    }
};

class Camel {
    int id;
    int x, y;
    bool isWhite;
};

ChessBoard chess = new ChessBoard();
chess.intialize();


bool  traversePath(int x, int y, int starty, int finaly, int rowDir, int colDir) {
    while(x != finalx && y != finaly) {
        if(chess.board[x][y] != '') return false;
        x+=rowDir;
        y+=colDir;
    }
    return true;
}
    
bool blockPresentInCamelPath(int startx, int starty, int finalx, int& finaly, bool isWhite) {
    int rowDir = finalx>startx ? 1 : -1;
    int colDir = finaly>starty ? 1 : -1;
    int x=startx+rowDir, y=starty+colDir;
    
    if(!traversePath()) return false;
    return chess.board[finax][finaly] == '' || chess.board[finax][finaly].second != isWhite;
}

bool moveCamel(int startx, int starty, int finalx, int finaly, bool isWhite) {
    if(abs(startx-finalx) == abs(starty-finaly)) {
        if(blockPresentInCamelPath(startx, starty, finalx, finaly)) return false;
        board[finalx][finaly].first = 'C';
        board[finalx][finaly].second = !isWhite;
        board[startx][starty].first = '';
        return true;
    }
    return false;
}

bool blockIsPresentInElePath(startx, starty, finalx, finaly) {
    int rowDir = startx==finalx ? 0 : finalx-startx / finalx-startx;
    int colDir = finaly==starty ? 0 : finaly-starty/ finaly-starty;
    
    
}

bool moveElephant(int startx, int starty, int finalx, int finaly, bool isWhite) {
    if(startx==finalx || starty==finaly) {
        if(blockIsPresentInElePath(startx, starty, finalx, finaly)) return false;
    }
    return false;
}

void move(int startx, int starty, int finalx, int finaly, bool isWhite) {
    pair<char, int> p = get(startx, starty);
    
    if(startx==finalx && starty==finaly) return false;
    if(!isInsideChess(finalx, finaly)) return false;
    if(board[finalx][finaly].second == isWhite && board[finalx][finaly].first != '') return false;
    
    bool canMove=false;
    switch(p.first) {
        case 'C' : canMove = moveCamel(startx, starty, finalx, finaly, bool isWhite);
            break;
        case 'E' : canMove = moveElephant(startx, int starty, int finalx, int finaly, bool isWhite);
    }
}


// startx,starty -> finalx, finaly //camel. //
//ordered_map<char, vector<pair<int, int>>> positions;

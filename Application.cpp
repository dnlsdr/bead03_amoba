#include "Application.hpp"

void Application::eventLoop(std::vector<std::vector<Board*>*> playBoard, int& timer)
{
    event ev;
    GameMaster gameMaster;
    while(gin >> ev)
    {
        gout << color(0, 0, 0)<< move_to(0, 0)<< box(window_width, 90);
        PlayerTurn playerTurn = PlayerTurn(-1);
        if (timer%2==0)
        {
            playerTurn = PlayerTurn(1);
        }
        else
        {
            playerTurn = PlayerTurn(-1);
        }
        playerTurn.display();

        if(!gameMaster.handle(1, playBoard) and !gameMaster.handle(-1, playBoard) and !gameMaster.isplayBoardFull(playBoard))
        {
            if(ev.type == ev_mouse and ev.button == btn_left)
            {
                for_each(playBoard.begin(), playBoard.end(), [ev, &timer, playBoard](const std::vector<Board*>* row)
                {
                    for_each(row->begin(), row->end(), [ev, &timer, playBoard](Board* box)
                    {
                        box->handle(ev, timer, playBoard);
                        box->drawing();
                    });
                });
            }
        }

        if(gameMaster.handle(1, playBoard))
        {
            GameFinishedBoard gameFinishedBoard = GameFinishedBoard(1);
            gameFinishedBoard.display();
        }
        else if(gameMaster.handle(-1, playBoard))
        {
            GameFinishedBoard gameFinishedBoard = GameFinishedBoard(-1);
            gameFinishedBoard.display();
        }
        else if(gameMaster.isplayBoardFull(playBoard))
        {
            GameFinishedBoard gameFinishedBoard = GameFinishedBoard(0);
            gameFinishedBoard.display();
        }

        gout << refresh;
    }
}

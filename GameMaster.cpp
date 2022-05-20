#include "GameMaster.hpp"
#include <iostream>

GameMaster::GameMaster(){}

bool GameMaster::rowScan(const int value, const std::vector<std::vector<Board*>*> playBoard)
{
    bool scan = false;
    endValue = value;
    for_each(playBoard.begin(), playBoard.end(),[this,&scan, &value](std::vector<Board*>* row)
    {
        for_each(row->begin(),row->end(), [this,&scan, &value](Board* box)
        {
            if(box->getValue()==endValue)
                {
                winningValue++;
                endValue = value;
                if(winningValue == 5)
                    {
                    scan=true;
                    }
                }
                else
                {
                    winningValue = 0;
                }
        });
    });
    return scan;
}

bool GameMaster::columnScan(const int value, const std::vector<std::vector<Board*>*> playBoard)
{
    endValue = value;
    bool scan = false;
    for(int i = 0; i < 15; i++)
    {
        //std::cout<<"i "<<i<<std::endl;
        for(int j = 0; j < 15; j++)
        {
            std::vector<Board*>* row = playBoard[j];
            Board* box = row[0][i];
            if(endValue==box->getValue())
            {
                winningValue++;
                endValue = value;
                if(winningValue == 5)
                {
                    scan=true;
                }
            }
            else
            {
                winningValue = 0;
            }
        }
    }
    return scan;
}

bool GameMaster::isplayBoardFull(const std::vector<std::vector<Board*>*> playBoard)
{
    bool isFull = true;

    for_each(playBoard.begin(), playBoard.end(), [&isFull](const std::vector<Board*>* row)
    {
        for_each(row->begin(), row->end(), [&isFull](Board* box)
        {
            if(box->getValue() == 0)
            {
                isFull = false;
            }
        });
    });

    return isFull;
}


bool GameMaster::crossLtoR(const int value, const std::vector<std::vector<Board*>*> playBoard)
{
    endValue = 0;
    int row_v = 0;
    int column_v = 0;
    bool scan = false;
    for(int i = 10; i > 0; i--)
    {
        for(int j = 0; j < 5 + column_v; j++)
        {
            std::vector<Board*>* row = playBoard[j];
            Board* box = row[0][i+j];
            if(endValue == box->getValue())
            {
                winningValue++;
                endValue = value;
                if(winningValue == 5)
                {
                    scan = true;
                }
            }
            else
            {
                winningValue = 0;
            }
        }
        column_v++;
    }
    for(int i = 10; i > 0; i--)
    {
        for(int j =0; j < 5 + row_v; j++)
        {
            std::vector<Board*>* row = playBoard[i + j];
            Board* box =row[0][j];
            if(endValue == box->getValue())
            {
                winningValue++;
                endValue = value;
                if(winningValue == 5)
                {
                    scan = true;
                }
            }
            else
            {
                winningValue = 0;
            }
        }
        row_v++;
    }


    return scan;
}

bool GameMaster::crossRtoL(const int value, const std::vector<std::vector<Board*>*> playBoard)
{
    endValue = 0;
    int row_v = 0;
    int column_v = 0;
    bool scan = false;
    for(int i = 10; i > 0; i--)
    {
        for(int j = 0; j < 5 + column_v; j++)
        {
            std::vector<Board*>* row = playBoard[14 - j];
            Board* box = row[0][i + j];
            if(endValue == box->getValue())
            {
                winningValue++;
                endValue = value;
                if(winningValue == 5)
                {
                    scan=true;
                }
            }
            else
            {
                winningValue = 0;
            }
        }
        column_v++;
    }
    for(int i = 5; i < 15; i++)
    {
        for(int j = 0; j < 5 + row_v; j++)
        {
            std::vector<Board*>* row = playBoard[i - j];
            Board* box = row[0][j];
            if(endValue == box->getValue())
            {
                winningValue++;
                endValue = value;
                if(winningValue == 5)
                {
                    scan=true;
                }
            }
            else
            {
                winningValue = 0;
            }
        }
        row_v++;
    }
    return scan;
}

bool GameMaster::handle(const int value, const std::vector<std::vector<Board*>*> playBoard)
{
    return (rowScan(value, playBoard) or columnScan(value, playBoard)
            or crossLtoR(value, playBoard) or crossRtoL(value, playBoard));
}

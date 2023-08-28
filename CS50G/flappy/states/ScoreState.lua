--[[
    ScoreState Class
    Author: Colton Ogden
    cogden@cs50.harvard.edu

    A simple state used to display the player's score before they
    transition back into the play state. Transitioned to from the
    PlayState when they collide with a Pipe.
]]

ScoreState = Class{__includes = BaseState}

--[[
    When we enter the score state, we expect to receive the score
    from the play state so we know what to render to the State.
]]
function ScoreState:enter(params)
    self.score = params.score
end

function ScoreState:update(dt)
    -- go back to play if enter is pressed
    if love.keyboard.wasPressed('enter') or love.keyboard.wasPressed('return') then
        gStateMachine:change('countdown')
    end
end

-- Load medal images
bronze = love.graphics.newImage('medal_bronze.png')
silver = love.graphics.newImage('medal_silver.png')
gold = love.graphics.newImage('medal_gold.png')

function ScoreState:render()
    -- simply render the score to the middle of the screen
    love.graphics.setFont(flappyFont)
    love.graphics.printf('Oof! You lost!', 0, 64, VIRTUAL_WIDTH, 'center')

    love.graphics.setFont(mediumFont)
    love.graphics.printf('Score: ' .. tostring(self.score), 0, 100, VIRTUAL_WIDTH, 'center')
    -- Choose the medal according to the score
    if 1 < self.score and self.score < 4 then
        medal = bronze
    end
    if 3 < self.score and self.score < 6 then
        medal = silver
    end
    if self.score > 5 then
        medal = gold
    end
    if self.score > 1 then
        love.graphics.draw(medal, VIRTUAL_WIDTH/2-medal:getWidth()/2, 120)
    end
    love.graphics.printf('Press Enter to Play Again!', 0, 160, VIRTUAL_WIDTH, 'center')
end

require 'game'
require 'neweru'

function CREATE_STATE(class, name)
    class['StateID_' + name] = game.State:new(class,
        class['beginState_' + name],
        class['executeState_' + name],
        class['endState_' + name],
        )
end

-- This is totally going to work on the first try :P

require 'bit32'

require 'game'
require 'neweru'
require 'neweru_macros'


local actorInfo = game.ActorInfo:new({8, -16, 0, 0, 0, 0, 0, 0, 0, 0, 0})
local profile = game.Profile:new({JumpBros.build, game.PURPLE_RING, 'JumpBros', actorInfo, 0})

local fileList = {'bros'}
neweru.ActorFiles(game.PURPLE_RING, 1, fileList)

local collisionInfo = {0, 16, 10, 16, 0, 3, 0, 0x26F, 0xFFFAFFFF, 0, game.Enemy.collisionCallback}

JumpBros = game.Enemy:new()

neweru_macros.CREATE_STATE(JumpBros, 'BeginJump')
neweru_macros.CREATE_STATE(JumpBros, 'DoJump')
neweru_macros.CREATE_STATE(JumpBros, 'EndJump')
neweru_macros.CREATE_STATE(JumpBros, 'WaitJump')

function JumpBros:onCreate()
    local archive = game.ResLoader.instance:getResArchive('bros')
    local mdl = archive:getModel('bros', 2, 1, 0, 0, 0, 0, 0)
    self.model = Model2:new(mdl, 2, 1, 0, 0, 0)
    self.model:init(archive, 0, 0)
    
    local direction = game:getDirectionToPlayer(self.position)
    self.rotation.Y = game.directionToRotationList[direction]
    
    self.physics:init(self, {0, 0, 0}, {0.0, 0.0, 32.0}, {4, 28, 8})
    
    self.collider:init(self, collisionInfo, 0)
    game.CollisionMgr.instance:addCollider(self.collider)
    
    self.physics:processCollisions()

    self:doStateChange(self.StateID_WaitJump)
    
    self:updateModel()

    return 1;
end

function JumpBros:onExecute()
    game.stateMgr.stateClass:executeState()
    self.updateModel()
    return 1
end

function JumpBros:onDraw()
    game.Drawer.instance:drawModel(self.model)
    return 1
end

function JumpBros:freezeActor()
    local info = game.IceInfo:new({1, self.position.X, self.position.Y + 2, self.position.Z + 2, 1.3, 1.1, 1.13, 0})
    return self.iceMgr:freezeActor(info, 1)
end

function JumpBros:playerCollision(selfCollider, otherCollider)
    local player = otherCollider.owner

    local hitType = self:processHit(selfCollider, otherCollider)

    if hitType == game.Side then
        game.Enemy.playerCollision(self, selfCollider, otherCollider)
    elseif hitType == game.Jump then
        self:killWithPlayer(player, {0.75, 2.0}, game.Enemy.StateID_JumpKill)
    elseif hitType == game.SpinJump then
        self:spinJumpKill(player)
    end
end

function JumpBros:yoshiCollision(selfCollider, otherCollider)
    local yoshi = otherCollider.owner

    local hitType = self:processHit(selfCollider, otherCollider)

    if hitType == game.Side then
        game.Enemy.yoshiCollision(self, selfCollider, otherCollider)
    elseif hitType == game.Jump then
        self:killWithYoshi(yoshi)
    end
end

function JumpBros:updateModel()
    local mtx = Mtx:new()
    game.calcMatrix(mtx, self.rotation, self.position)
    self.model.obj:setMatrix(mtx)
    self.model.obj:setScale(self.scale)
    self.model.obj:vf6C()
    self.model.obj:vf74()
    self.model:update()
end

function JumpBros:beginState_BeginJump()
    model.sklAnims.anims[0]:play(self.archive, 'jump_st')
    model.sklAnims.anims[0]:setRepeat(false)
end

function JumpBros:executeState_BeginJump()
    if bit32.band(model.sklAnims.anims[0].flags, 0x20) then
        self:doStateChange(StateID_DoJump)
    end
end

function JumpBros:endState_BeginJump() end

function JumpBros:beginState_DoJump()
    model.sklAnims.anims[0]:play(self.archive, 'jump_md')
    model.sklAnims.anims[0]:setRepeat(false)
    self.speed.Y = 6
end

function JumpBros:executeState_DoJump()
    self:applyGravity()
    self:updatePosition()
    self.physics:processCollisions()

    if bit32.band(self.physics.collisionFlags[0], 1) then
        self:doStateChange(StateID_EndJump)
    end
end

function JumpBros:endState_DoJump() end

function JumpBros:beginState_EndJump()
    model.sklAnims.anims[0]:play(self.archive, 'jump_ed')
    model.sklAnims.anims[0]:setRepeat(false)
end

function JumpBros:executeState_EndJump()
    if bit32.band(self.model.sklAnims.anims[0].flags, 0x20 then
        self:doStateChange(StateID_WaitJump)
    end
end

function JumpBros:endState_EndJump() end

function JumpBros:beginState_WaitJump()
    self.timer = 20
end

function JumpBros:executeState_WaitJump()
    self.timer -= 1
    if self.timer == 0 then
        self:doStateChange(StateID_BeginJump)
    end
end

function JumpBros:endState_WaitJump() end

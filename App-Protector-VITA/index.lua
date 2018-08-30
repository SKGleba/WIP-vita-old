white = Color.new(255, 255, 255)
cyan = Color.new(0, 255, 255)
funny = Color.new(100, 0, 200)
warn = Color.new(255, 0, 0)
::start::
qad = "ux0:app/"
vm = true
ispfsapp = false
already = false
nosfo = false
ttid = "lolz"
::qrld::
appz = System.listDirectory(qad)
image = Graphics.loadImage("app0:sce_sys/pic0.png")
p = 2
i = 1
while true do
	y = 120+(-i*50)
	Graphics.initBlend()
	Screen.clear()
	Graphics.drawImage(0, 0, image)
	Graphics.debugPrint(450, 25, "APP PROTECTOR BY SKGLEBA.", white)
if vm == false or System.doesFileExist("ux0:app/" .. appz[i].name .. "/sce_sys/param.sfo") == true then
nosfo = false
if vm == false or System.doesDirExist("ux0:app/" .. appz[i].name .. "/sce_pfs/") == false then
ispfsapp = false
    if vm == false and System.doesDirExist("ur0:temp/pwd/" .. appz[i].name .. "/") == false then
already = false
	Graphics.debugPrint(450, 75, "Press cross to change password", white)
elseif not vm == false and System.doesDirExist("ur0:temp/pwd/" .. appz[i].name .. "/") == false then
already = false
	Graphics.debugPrint(450, 75, "Press cross to set password", white)
elseif not vm == false and System.doesDirExist("ur0:temp/pwd/" .. appz[i].name .. "/") == true then
already = true
	Graphics.debugPrint(450, 75, "Press cross to switch to password manager", white)
end
	Graphics.debugPrint(450, 110, "Press triangle to remove password", white)
    if vm == false then
	Graphics.debugPrint(450, 145, "Press circle to switch to app selector", white)
else
	Graphics.debugPrint(450, 145, "Press square to block/unblock henkaku", white)
end
else
ispfsapp = true
	Graphics.debugPrint(450, 250, "Not working on pfs protected apps!!!", warn)
end
else 
nosfo = true
	Graphics.debugPrint(450, 250, "Not a app!!!", warn)
end
	Graphics.debugPrint(750, 500, "BETA 4", funny)
	
	for j, file in pairs(appz) do
		x = 20
		if i == j then
			color = cyan
currp = qad .. appz[i].name .. "/sce_sys/param.sfo"
if System.doesFileExist(currp) == true then
info = System.extractSfo(currp)
Graphics.debugPrint(x, y, info.title, color)
else
Graphics.debugPrint(x, y, file.name, color)
end
			x = 25
		elseif i == j + 1 then
			color = white
currp = qad .. appz[i - 1].name .. "/sce_sys/param.sfo"
if System.doesFileExist(currp) == true then
info = System.extractSfo(currp)
Graphics.debugPrint(x, y, info.title, color)
else
Graphics.debugPrint(x, y, file.name, color)
end
		elseif i == j - 1 then
			color = white
currp = qad .. appz[i + 1].name .. "/sce_sys/param.sfo"
if System.doesFileExist(currp) == true then
info = System.extractSfo(currp)
Graphics.debugPrint(x, y, info.title, color)
else
Graphics.debugPrint(x, y, file.name, color)
end
		elseif i == j - 2 then
			color = white
currp = qad .. appz[i + 2].name .. "/sce_sys/param.sfo"
if System.doesFileExist(currp) == true then
info = System.extractSfo(currp)
Graphics.debugPrint(x, y, info.title, color)
else
Graphics.debugPrint(x, y, file.name, color)
end
		elseif i == j - 3 then
			color = white
currp = qad .. appz[i + 3].name .. "/sce_sys/param.sfo"
if System.doesFileExist(currp) == true then
info = System.extractSfo(currp)
Graphics.debugPrint(x, y, info.title, color)
else
Graphics.debugPrint(x, y, file.name, color)
end
		elseif i == j - 4 then
			color = white
currp = qad .. appz[i + 4].name .. "/sce_sys/param.sfo"
if System.doesFileExist(currp) == true then
info = System.extractSfo(currp)
Graphics.debugPrint(x, y, info.title, color)
else
Graphics.debugPrint(x, y, file.name, color)
end
		elseif i == j - 5 then
			color = white
currp = qad .. appz[i + 5].name .. "/sce_sys/param.sfo"
if System.doesFileExist(currp) == true then
info = System.extractSfo(currp)
Graphics.debugPrint(x, y, info.title, color)
else
Graphics.debugPrint(x, y, file.name, color)
end
		elseif i == j - 6 then
			color = white
currp = qad .. appz[i + 6].name .. "/sce_sys/param.sfo"
if System.doesFileExist(currp) == true then
info = System.extractSfo(currp)
Graphics.debugPrint(x, y, info.title, color)
else
Graphics.debugPrint(x, y, file.name, color)
end
		elseif i == j - 7 then
			color = white
currp = qad .. appz[i + 7].name .. "/sce_sys/param.sfo"
if System.doesFileExist(currp) == true then
info = System.extractSfo(currp)
Graphics.debugPrint(x, y, info.title, color)
else
Graphics.debugPrint(x, y, file.name, color)
end
		elseif i == j - 8 then
			color = white
currp = qad .. appz[i + 8].name .. "/sce_sys/param.sfo"
if System.doesFileExist(currp) == true then
info = System.extractSfo(currp)
Graphics.debugPrint(x, y, info.title, color)
else
Graphics.debugPrint(x, y, file.name, color)
end
		elseif i == j - 9 then
			color = white
currp = qad .. appz[i + 9].name .. "/sce_sys/param.sfo"
if System.doesFileExist(currp) == true then
info = System.extractSfo(currp)
Graphics.debugPrint(x, y, info.title, color)
else
Graphics.debugPrint(x, y, file.name, color)
end
		end
		
		y = y + 50
	end
	Graphics.termBlend()

	pad = Controls.read()
	if Controls.check(pad, SCE_CTRL_CROSS) and ispfsapp == false and nosfo == false then
        if already == true and not vm == false then
            qad = "ur0:temp/pwd/" .. appz[i].name .. "/"
            vm = false
       goto qrld
       
        elseif vm == false then

        System.rename(qad .. appz[i].name, qad .. "LaunchToSetPassword")
else
        System.rename("ux0:/app/" .. appz[i].name .. "/eboot.bin", "ux0:/app/" .. appz[i].name .. "/eboot.bin2")
        System.extractZip("ux0:/app/SKGPWDPR7/ADD/toapp.zip", "ux0:/app/" .. appz[i].name)
		System.launchApp(appz[i].name)
        System.exit()
end

	elseif Controls.check(pad, SCE_CTRL_SQUARE) and ispfsapp == false and nosfo == false then
        System.launchEboot("app0:hblock")
        System.exit()
	elseif Controls.check(pad, SCE_CTRL_TRIANGLE) and ispfsapp == false and nosfo == false then
        if vm == false then
            System.deleteDirectory(qad)
       goto qrld
else
		System.deleteFile("ux0:/app/" .. appz[i].name .. "/eboot.bin")
        System.rename("ux0:/app/" .. appz[i].name .. "/eboot.bin2", "ux0:/app/" .. appz[i].name .. "/eboot.bin")
		goto start
end
	elseif Controls.check(pad, SCE_CTRL_CIRCLE) then
  goto start

              

	elseif Controls.check(pad, SCE_CTRL_UP) and not Controls.check(oldpad, SCE_CTRL_UP) then
		i = i - 1

	elseif Controls.check(pad, SCE_CTRL_DOWN) and not Controls.check(oldpad, SCE_CTRL_DOWN) then
		i = i + 1

	elseif Controls.check(pad, SCE_CTRL_LEFT) and not Controls.check(oldpad, SCE_CTRL_LEFT) then
		i = i - 5
	elseif Controls.check(pad, SCE_CTRL_RIGHT) and not Controls.check(oldpad, SCE_CTRL_RIGHT) then
		i = i + 5
	end
	
	if i > #appz then
		i = 1
	elseif i < 1 then
		i = #appz
	end
	
	-- Update oldpad and flip screen
	oldpad = pad
	Screen.flip()
	
end


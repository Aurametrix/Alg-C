GameUnit camera = ...;
GameUnit juliet = ...;
GameUnit curtains = ...;

cr::CoroutineSet coroutine_set;

coroutine_set.start("end_scene", [&](cr::InnerControl& ic){
    while (!camera.looking_at(juliet)) {
        camera.turn_towards(juliet);
        ic.yield(); // Return to the calling thread
    }
    juliet.speak("Romeo, I come! This do I drink to thee.");
    ic.wait_sec(2.0); // Yield to main thread for the next two seconds
    auto drink_animation = juliet.animate("drink_poison");
    ic.wait_for([&](){ return drink_animation.is_done(); });
    auto fall_animation = juliet.animate("fall_to_the_ground");;
    ic.wait_for([&](){ return fall_animation.is_done(); });
    ic.wait_sec(1.0);
    curtains.animate("drop");
    ic.wait_sec(2.0);
});

// Game loop:
for (;;) {
    double dt = seconds_since_last_frame();
    input();
    update(dt);
    coroutine_set.poll(dt); // Allow coroutines to run for a short while
    paint();
}

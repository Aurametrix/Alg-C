if get_param('use_convnet_for_thing1', True):
        convnet1_params = get_param('convnet1_params', None)
        thing1 = build_convnet(thing1_input, convnet1_params)
    elif ...

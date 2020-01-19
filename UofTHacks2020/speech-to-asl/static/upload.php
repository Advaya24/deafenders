<?php

    if(!empty($_POST['data'])){
        $data = $_POST['data'];
        $fname = mktime() . ".txt";//generates random name

        $file = fopen("/static/" .$fname, 'w');//creates new file
        print("Hello");
        fwrite($file, $data);
        fclose($file);
    }

?>

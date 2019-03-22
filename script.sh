#!/usr/bin/sh

leak=$(valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all)
lem-in_correct=./resources/sortie_error_lem_in_correct
visu_correct=./resources/sortie_error_visu_correct
lem-in_error=./resources/sortie_error_lem_in_error
visu_error=./resources/sortie_error_visu_error


ma_fonction(){
	echo "\n\nContinue? y/n "
	read mot
	case "$mot" in
		quit | q | Q | exit | n ) echo "See you soon!" && exit;;
	esac
}

if [ "$1" = "visu" ]
then
	if [ "$2" = "correct" ]; then
		$leak ./lem-in < resources/correct/1.map 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/10.map 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/2.map 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/5.map 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_1 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_2 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_3 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_4 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_5 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_6 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_7 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_8 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_9 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_10 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_genc_1 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_genc_2 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correctc_10 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/error1 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/example 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/example2 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/example3 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/good_map_lot_of_room_without_pipe 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/good_map_no_com 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/good_map_one_room_without_pipe 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/good_map_one_room_without_pipe 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/goodmap_aaa 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/goodmap_end_next_to_start 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/goodmap_jjj 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/goodmap_kkk 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/goodmap_multiple_way_differents_dist 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/goodmap_oulah 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/goodmap_test 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/map_git 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/map_git1 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/map_git2 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/map_git3 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/map_offi 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/pretty 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/subject.txt 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/test 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/test1 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/test_boucle 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/totomap 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/bad_map_3 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/10_lots_of_comments.map 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/invalide_map 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/bad_map2 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/trickytrickymap 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/map_genius2 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/map_genius 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
	# petite resolution et pas de visu
		$leak ./lem-in < resources/correct/correct_11 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/big 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/g 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_genc_3 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/map_offi_custom 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/maptest 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/anil 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
	# grosse resolution et pas de visu
		$leak ./lem-in < resources/correct/lll 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/9_path_depth_4_ants2.map 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/9_path_depth_2_ants2.map 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/9_path_depth_1_ants2.map 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/9_path_depth_10_ants2.map 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/9_path_depth_8_ants.map 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/9_path_depth_9_ants.map 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_genc_4 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_genc_5 2>> $lem-in_correct | ./visu 2>> $visu_correct
		ma_fonction
	else [ "$2" = "error" ]
		$leak ./lem-in < resources/error/err_no_path.map 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/impossible.txt 2>$lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/map_offi_no_way 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/new_map 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < srcs 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < auteur 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < lem-in 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_no_links.map 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/2 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/20.map 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/bad_map 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/bad_map_4 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/comment.txt 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/correct_gen_1 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/correct_gen_2 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/correct_gen_3 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/correct_gen_4 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/double_end.txt 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/double_start.txt 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_3_coordinates.map 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_duplicate.map 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_empty.map 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_letter_in_coordinate.map 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_link_to_unknown_room.map 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_no_ants.map 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_no_ants2.map 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_no_ants3.map 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_no_end2.map 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_no_rooms.map 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_no_start.map 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_too_few_ants.map 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_too_many_ants.map 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error2 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error3 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error4 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error5 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error6 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/impossible2.txt 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/invalid_pipe.txt 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/little.txt 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/map_edit 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/map_incorrect_gen 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/map_multiple_pipe_from_one_room_to_another 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/no_end.txt 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/no_start.txt 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/norooms 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/test.txt 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrong_map_empty 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_map_multiple_end 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_multiple_start 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_nawak 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_no_way_to_the_end 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_noant 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_noend 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_noend_nostart 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_nopipe 2>> $lem-in_error | $leak ./visu 2>> $visu_error
<<<<<<< HEAD
		$leak ./lem-in < resources/error/wrongmap_noroom 2>> $lem-in_error | $leak ./visu 2>> $visu_error
=======
		$leak ./lem-im < resources/error/wrongmap_noroom 2>> $lem-in_error | $leak ./visu 2>> $visu_error
>>>>>>> glebouch
		$leak ./lem-in < resources/error/wrongmap_nostart 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_start_end 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_wrong_ant 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_wrong_coordonne 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_wrong_pipe_name 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_wrong_room_name 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_wrong_room_name_2 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_zero_ant 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_1 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_2 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_3 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_4 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_5 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_6 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_7 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_8 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_9 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_10 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_11 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_12 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_13 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_14 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_15 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_16 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_17 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_18 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_19 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_20 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_21 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_22 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_23 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_24 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_25 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_26 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_27 2>> $lem-in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/map_offi_pipe_error 2>> $lem-in_error | $leak ./visu 2>> $visu_error
	fi
fi

if [ "$1" = "correct" ]
then
	$leak ./lem-in < resources/correct/1 2> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/1.map 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/10.map 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/2.map 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/5.map 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/correct_1 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/correct_2 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/correct_3 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/correct_4 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/correct_5 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/correct_6 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/correct_7 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/correct_8 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/correct_9 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/correct_10 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/correct_genc_1 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/correct_genc_2 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/correctc_10 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/error1 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/example 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/example2 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/example3 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/good_map_lot_of_room_without_pipe 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/good_map_no_com 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/good_map_one_room_without_pipe 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/good_map_one_room_without_pipe 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/goodmap_aaa 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/goodmap_end_next_to_start 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/goodmap_jjj 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/goodmap_kkk 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/goodmap_multiple_way_differents_dist 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/goodmap_oulah 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/goodmap_test 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/map_git 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/map_git1 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/map_git2 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/map_git3 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/map_offi 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/pretty 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/subject.txt 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/test 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/test1 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/test_boucle 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/totomap 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/bad_map_3 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/10_lots_of_comments.map 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/invalide_map 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/bad_map2 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/trickytrickymap 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/map_genius2 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/map_genius 2>> $lem-in_correct
	ma_fonction
# petit
	$leak ./lem-in < resources/correct/correct_11 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/big 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/g 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/correct_genc_3 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/map_offi_custom 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/maptest 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/anil 2>> $lem-in_correct
	ma_fonction
# grosse resolution et pas de visu
	$leak ./lem-in < resources/correct/lll 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/9_path_depth_4_ants2.map 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/9_path_depth_2_ants2.map 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/9_path_depth_1_ants2.map 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/9_path_depth_10_ants2.map 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/9_path_depth_8_ants.map 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/9_path_depth_9_ants.map 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/correct_genc_4 2>> $lem-in_correct
	ma_fonction
	$leak ./lem-in < resources/correct/correct_genc_5 2>> $lem-in_correct
fi

if [ "$1" = "error" ]
then
	$leak ./lem-in < resources/error/err_no_path.map 2>> $lem-in_error
	$leak ./lem-in < resources/error/impossible.txt 2>$lem-in_error
	$leak ./lem-in < resources/error/map_offi_no_way 2>> $lem-in_error
	$leak ./lem-in < resources/error/new_map 2>> $lem-in_error
	$leak ./lem-in < srcs 2>> $lem-in_error
	$leak ./lem-in < auteur 2>> $lem-in_error
	$leak ./lem-in < lem-in 2>> $lem-in_error
	$leak ./lem-in < resources/error/err_no_links.map 2>> $lem-in_error
	$leak ./lem-in < resources/error/2 2>> $lem-in_error
	$leak ./lem-in < resources/error/20.map 2>> $lem-in_error
	$leak ./lem-in < resources/error/bad_map 2>> $lem-in_error
	$leak ./lem-in < resources/error/bad_map_4 2>> $lem-in_error
	$leak ./lem-in < resources/error/comment.txt 2>> $lem-in_error
	$leak ./lem-in < resources/error/correct_gen_1 2>> $lem-in_error
	$leak ./lem-in < resources/error/correct_gen_2 2>> $lem-in_error
	$leak ./lem-in < resources/error/correct_gen_3 2>> $lem-in_error
	$leak ./lem-in < resources/error/correct_gen_4 2>> $lem-in_error
	$leak ./lem-in < resources/error/double_end.txt 2>> $lem-in_error
	$leak ./lem-in < resources/error/double_start.txt 2>> $lem-in_error
	$leak ./lem-in < resources/error/err_3_coordinates.map 2>> $lem-in_error
	$leak ./lem-in < resources/error/err_duplicate.map 2>> $lem-in_error
	$leak ./lem-in < resources/error/err_empty.map 2>> $lem-in_error
	$leak ./lem-in < resources/error/err_letter_in_coordinate.map 2>> $lem-in_error
	$leak ./lem-in < resources/error/err_link_to_unknown_room.map 2>> $lem-in_error
	$leak ./lem-in < resources/error/err_no_ants.map 2>> $lem-in_error
	$leak ./lem-in < resources/error/err_no_ants2.map 2>> $lem-in_error
	$leak ./lem-in < resources/error/err_no_ants3.map 2>> $lem-in_error
	$leak ./lem-in < resources/error/err_no_end2.map 2>> $lem-in_error
	$leak ./lem-in < resources/error/err_no_rooms.map 2>> $lem-in_error
	$leak ./lem-in < resources/error/err_no_start.map 2>> $lem-in_error
	$leak ./lem-in < resources/error/err_too_few_ants.map 2>> $lem-in_error
	$leak ./lem-in < resources/error/err_too_many_ants.map 2>> $lem-in_error
	$leak ./lem-in < resources/error/error2 2>> $lem-in_error
	$leak ./lem-in < resources/error/error3 2>> $lem-in_error
	$leak ./lem-in < resources/error/error4 2>> $lem-in_error
	$leak ./lem-in < resources/error/error5 2>> $lem-in_error
	$leak ./lem-in < resources/error/error6 2>> $lem-in_error
	$leak ./lem-in < resources/error/impossible2.txt 2>> $lem-in_error
	$leak ./lem-in < resources/error/invalid_pipe.txt 2>> $lem-in_error
	$leak ./lem-in < resources/error/little.txt 2>> $lem-in_error
	$leak ./lem-in < resources/error/map_edit 2>> $lem-in_error
	$leak ./lem-in < resources/error/map_incorrect_gen 2>> $lem-in_error
	$leak ./lem-in < resources/error/map_multiple_pipe_from_one_room_to_another 2>> $lem-in_error
	$leak ./lem-in < resources/error/no_end.txt 2>> $lem-in_error
	$leak ./lem-in < resources/error/no_start.txt 2>> $lem-in_error
	$leak ./lem-in < resources/error/norooms 2>> $lem-in_error
	$leak ./lem-in < resources/error/test.txt 2>> $lem-in_error
	$leak ./lem-in < resources/error/wrong_map_empty 2>> $lem-in_error
	$leak ./lem-in < resources/error/wrongmap_map_multiple_end 2>> $lem-in_error
	$leak ./lem-in < resources/error/wrongmap_multiple_start 2>> $lem-in_error
	$leak ./lem-in < resources/error/wrongmap_nawak 2>> $lem-in_error
	$leak ./lem-in < resources/error/wrongmap_no_way_to_the_end 2>> $lem-in_error
	$leak ./lem-in < resources/error/wrongmap_noant 2>> $lem-in_error
	$leak ./lem-in < resources/error/wrongmap_noend 2>> $lem-in_error
	$leak ./lem-in < resources/error/wrongmap_noend_nostart 2>> $lem-in_error
	$leak ./lem-in < resources/error/wrongmap_nopipe 2>> $lem-in_error
	$leak ./lem-in < resources/error/wrongmap_noroom 2>> $lem-in_error
	$leak ./lem-in < resources/error/wrongmap_nostart 2>> $lem-in_error
	$leak ./lem-in < resources/error/wrongmap_start_end 2>> $lem-in_error
	$leak ./lem-in < resources/error/wrongmap_wrong_ant 2>> $lem-in_error
	$leak ./lem-in < resources/error/wrongmap_wrong_coordonne 2>> $lem-in_error
	$leak ./lem-in < resources/error/wrongmap_wrong_pipe_name 2>> $lem-in_error
	$leak ./lem-in < resources/error/wrongmap_wrong_room_name 2>> $lem-in_error
	$leak ./lem-in < resources/error/wrongmap_wrong_room_name_2 2>> $lem-in_error
	$leak ./lem-in < resources/error/wrongmap_zero_ant 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_1 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_2 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_3 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_4 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_5 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_6 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_7 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_8 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_9 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_10 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_11 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_12 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_13 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_14 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_15 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_16 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_17 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_18 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_19 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_20 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_21 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_22 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_23 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_24 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_25 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_26 2>> $lem-in_error
	$leak ./lem-in < resources/error/error_27 2>> $lem-in_error
	$leak ./lem-in < resources/error/map_offi_pipe_error 2>> $lem-in_error
fi

echo "done"
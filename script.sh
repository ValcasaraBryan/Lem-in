#!/usr/bin/sh

leak="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes"
lem_in_correct=./resources/sortie_error_lem_in_correct
visu_correct=./resources/sortie_error_visu_correct
lem_in_error=./resources/sortie_error_lem_in_error
visu_error=./resources/sortie_error_visu_error
sortie_verif=./resources/sortie_verif
result=./resources/result_checker

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
		$leak ./lem-in < resources/correct/1.map 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/10.map 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/2.map 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/5.map 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_1 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_2 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_3 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_4 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_5 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_6 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_7 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_8 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_9 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_10 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_genc_1 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_genc_2 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correctc_10 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/error1 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/example 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/example2 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/example3 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/good_map_lot_of_room_without_pipe 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/good_map_no_com 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/good_map_one_room_without_pipe 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/good_map_one_room_without_pipe 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/goodmap_aaa 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/goodmap_end_next_to_start 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/goodmap_jjj 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/goodmap_kkk 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/goodmap_multiple_way_differents_dist 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/goodmap_oulah 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/goodmap_test 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/map_git 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/map_git1 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/map_git2 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/map_git3 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/map_offi 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/pretty 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/subject.txt 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/test 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/test1 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/test_boucle 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/totomap 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/bad_map_3 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/10_lots_of_comments.map 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/invalide_map 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/bad_map2 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/trickytrickymap 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/map_genius2 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/map_genius 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
	# petite resolution et pas de visu
		$leak ./lem-in < resources/correct/correct_11 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/g 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_genc_3 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/map_offi_custom 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/maptest 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/anil 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
	# grosse resolution et pas de visu
		$leak ./lem-in < resources/correct/lll 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/9_path_depth_4_ants2.map 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/9_path_depth_2_ants2.map 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/9_path_depth_1_ants2.map 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/9_path_depth_10_ants2.map 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/9_path_depth_8_ants.map 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/9_path_depth_9_ants.map 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_genc_4 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
		$leak ./lem-in < resources/correct/correct_genc_5 2>> $lem_in_correct | ./visu 2>> $visu_correct
		ma_fonction
	else [ "$2" = "error" ]
		$leak ./lem-in < resources/error/err_no_path.map 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/impossible.txt 2>$lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/map_offi_no_way 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/new_map 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < srcs 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < auteur 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < lem-in 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_no_links.map 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/2 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/20.map 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/bad_map 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/bad_map_4 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/comment.txt 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/correct_gen_1 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/correct_gen_2 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/correct_gen_3 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/correct_gen_4 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/double_end.txt 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/double_start.txt 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_3_coordinates.map 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_duplicate.map 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_empty.map 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_letter_in_coordinate.map 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_link_to_unknown_room.map 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_no_ants.map 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_no_ants2.map 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_no_ants3.map 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_no_end2.map 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_no_rooms.map 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_no_start.map 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_too_few_ants.map 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/err_too_many_ants.map 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error2 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error3 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error4 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error5 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error6 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/impossible2.txt 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/invalid_pipe.txt 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/little.txt 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/map_edit 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/map_incorrect_gen 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/map_multiple_pipe_from_one_room_to_another 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/no_end.txt 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/no_start.txt 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/norooms 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/test.txt 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrong_map_empty 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_map_multiple_end 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_multiple_start 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_nawak 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_no_way_to_the_end 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_noant 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_noend 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_noend_nostart 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_nopipe 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-im < resources/error/wrongmap_noroom 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_nostart 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_start_end 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_wrong_ant 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_wrong_coordonne 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_wrong_pipe_name 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_wrong_room_name 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_wrong_room_name_2 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/wrongmap_zero_ant 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_1 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_2 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_3 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_4 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_5 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_6 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_7 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_8 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_9 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_10 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_11 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_12 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_13 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_14 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_15 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_16 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_17 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_18 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_19 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_20 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_21 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_22 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_23 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_24 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_25 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_26 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/error_27 2>> $lem_in_error | $leak ./visu 2>> $visu_error
		$leak ./lem-in < resources/error/map_offi_pipe_error 2>> $lem_in_error | $leak ./visu 2>> $visu_error
	fi
fi
if [ "$1" = "correct" ]
then

#	$leak ./lem-in < resources/correct/1 2> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/1.map 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/10.map 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/5.map 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/correct_1 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/correct_2 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/correct_3 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/correct_4 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/correct_5 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/correct_6 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/correct_7 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/correct_8 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/correct_9 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/correct_10 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/correct_genc_1 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/correct_genc_2 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/correctc_10 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/error1 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/example 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/example2 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/example3 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/good_map_lot_of_room_without_pipe 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/good_map_no_com 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/good_map_one_room_without_pipe 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/good_map_one_room_without_pipe 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/goodmap_aaa 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/goodmap_end_next_to_start 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/goodmap_jjj 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/goodmap_kkk 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/goodmap_multiple_way_differents_dist 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/goodmap_oulah 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/goodmap_test 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/map_git 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/map_git1 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/map_git2 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/map_git3 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/map_offi 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/pretty 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/subject.txt 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/test 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/test1 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/test_boucle 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/totomap 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/bad_map_3 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/10_lots_of_comments.map 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/invalide_map 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/bad_map2 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/trickytrickymap 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/map_genius2 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/map_genius 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
## petit 
#	$leak ./lem-in < resources/correct/correct_11 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/g 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/correct_genc_3 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/map_offi_custom 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/maptest 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/anil 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
## grosse resolution et pas de visu
#	$leak ./lem-in < resources/correct/lll 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/9_path_depth_4_ants2.map 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/9_path_depth_2_ants2.map 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/9_path_depth_1_ants2.map 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/9_path_depth_10_ants2.map 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/9_path_depth_8_ants.map 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/9_path_depth_9_ants.map 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/correct_genc_4 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/correct_genc_5 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#
#	$leak ./lem-in < resources/correct/flow_one/flow_one_1 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_2 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_3 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_4 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_5 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_6 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_7 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_8 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_9 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_10 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#
#	$leak ./lem-in < resources/correct/flow_one/flow_one_11 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_12 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_13 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_14 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_15 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_16 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_17 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_18 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_19 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_20 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#
#	$leak ./lem-in < resources/correct/flow_one/flow_one_31 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_32 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_33 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_34 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_35 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_36 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_37 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_38 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_39 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_40 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#
#	$leak ./lem-in < resources/correct/flow_one/flow_one_41 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_42 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_43 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_44 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_45 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_46 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_47 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_48 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_49 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_one/flow_one_50 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_1 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_2 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_3 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_4 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_5 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_6 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_7 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_8 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_9 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_10 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_11 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_12 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_13 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_14 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_15 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_16 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_17 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_18 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_19 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_20 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_21 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_22 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_23 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_24 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_25 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_26 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_27 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_28 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_29 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_30 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_31 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_32 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_33 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_34 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_35 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_36 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_37 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_38 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_39 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_40 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_41 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_42 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_43 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_44 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_45 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_46 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_47 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_48 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_49 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_ten/flow_ten_50 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_1 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_2 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_3 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_4 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_5 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_6 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_7 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_8 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_9 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_10 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_11 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_12 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_13 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_14 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_15 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_16 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_17 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_18 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_19 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_20 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_21 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_22 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_23 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_24 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_25 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_26 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_27 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_28 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_29 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_30 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_31 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_32 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_33 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_34 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_35 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_36 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_37 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_38 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_39 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_40 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_41 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_42 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_43 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_44 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_45 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_46 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_47 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_48 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_49 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/flow_thousand/flow_thousand_50 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#
#	$leak ./lem-in < resources/correct/big/big_1 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_2 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_3 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_4 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_5 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_6 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_7 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_8 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_9 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_10 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#
#	$leak ./lem-in < resources/correct/big/big_11 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_12 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_13 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_14 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_15 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_16 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_17 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_18 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_19 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_20 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#
#	$leak ./lem-in < resources/correct/big/big_21 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_22 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_23 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_24 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_25 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_26 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_27 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_28 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_29 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_30 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#
#	$leak ./lem-in < resources/correct/big/big_31 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_32 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_33 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_34 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_35 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_36 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_37 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_38 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_39 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_40 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#
#	$leak ./lem-in < resources/correct/big/big_41 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_42 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_43 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_44 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_45 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_46 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_47 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_48 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_49 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result
#	$leak ./lem-in < resources/correct/big/big_50 2>> $lem_in_correct > $sortie_verif && make check arg=$sortie_verif arg_2=$result

	echo resources/correct/big_superposition/big_superposition_1
	time ./lem-in < resources/correct/big_superposition/big_superposition_1 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_2
	time ./lem-in < resources/correct/big_superposition/big_superposition_2 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_3
	time ./lem-in < resources/correct/big_superposition/big_superposition_3 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_4
	time ./lem-in < resources/correct/big_superposition/big_superposition_4 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_5
	time ./lem-in < resources/correct/big_superposition/big_superposition_5 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_6
	time ./lem-in < resources/correct/big_superposition/big_superposition_6 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_7
	time ./lem-in < resources/correct/big_superposition/big_superposition_7 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_8
	time ./lem-in < resources/correct/big_superposition/big_superposition_8 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_9
	time ./lem-in < resources/correct/big_superposition/big_superposition_9 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_10
	time ./lem-in < resources/correct/big_superposition/big_superposition_10 > $sortie_verif && make check arg=$sortie_verif arg_2=$result

	echo resources/correct/big_superposition/big_superposition_11
	time ./lem-in < resources/correct/big_superposition/big_superposition_11 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_12
	time ./lem-in < resources/correct/big_superposition/big_superposition_12 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_13
	time ./lem-in < resources/correct/big_superposition/big_superposition_13 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_14
	time ./lem-in < resources/correct/big_superposition/big_superposition_14 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_15
	time ./lem-in < resources/correct/big_superposition/big_superposition_15 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_16
	time ./lem-in < resources/correct/big_superposition/big_superposition_16 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_17
	time ./lem-in < resources/correct/big_superposition/big_superposition_17 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_18
	time ./lem-in < resources/correct/big_superposition/big_superposition_18 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_19
	time ./lem-in < resources/correct/big_superposition/big_superposition_19 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_20
	time ./lem-in < resources/correct/big_superposition/big_superposition_20 > $sortie_verif && make check arg=$sortie_verif arg_2=$result

	echo resources/correct/big_superposition/big_superposition_21
	time ./lem-in < resources/correct/big_superposition/big_superposition_21  > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_22
	time ./lem-in < resources/correct/big_superposition/big_superposition_22  > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_23
	time ./lem-in < resources/correct/big_superposition/big_superposition_23  > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_24
	time ./lem-in < resources/correct/big_superposition/big_superposition_24  > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_25
	time ./lem-in < resources/correct/big_superposition/big_superposition_25  > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_26
	time ./lem-in < resources/correct/big_superposition/big_superposition_26  > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_27
	time ./lem-in < resources/correct/big_superposition/big_superposition_27  > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_28
	time ./lem-in < resources/correct/big_superposition/big_superposition_28  > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_29
	time ./lem-in < resources/correct/big_superposition/big_superposition_29  > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_30
	time ./lem-in < resources/correct/big_superposition/big_superposition_30  > $sortie_verif && make check arg=$sortie_verif arg_2=$result

	echo resources/correct/big_superposition/big_superposition_31
	time ./lem-in < resources/correct/big_superposition/big_superposition_31 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_32
	time ./lem-in < resources/correct/big_superposition/big_superposition_32 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_33
	time ./lem-in < resources/correct/big_superposition/big_superposition_33 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_34
	time ./lem-in < resources/correct/big_superposition/big_superposition_34 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_35
	time ./lem-in < resources/correct/big_superposition/big_superposition_35 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_36
	time ./lem-in < resources/correct/big_superposition/big_superposition_36 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_37
	time ./lem-in < resources/correct/big_superposition/big_superposition_37 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_38
	time ./lem-in < resources/correct/big_superposition/big_superposition_38 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_39
	time ./lem-in < resources/correct/big_superposition/big_superposition_39 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_40
	time ./lem-in < resources/correct/big_superposition/big_superposition_40 > $sortie_verif && make check arg=$sortie_verif arg_2=$result

	echo resources/correct/big_superposition/big_superposition_41
	time ./lem-in < resources/correct/big_superposition/big_superposition_41 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_42
	time ./lem-in < resources/correct/big_superposition/big_superposition_42 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_43
	time ./lem-in < resources/correct/big_superposition/big_superposition_43 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_44
	time ./lem-in < resources/correct/big_superposition/big_superposition_44 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_45
	time ./lem-in < resources/correct/big_superposition/big_superposition_45 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_46
	time ./lem-in < resources/correct/big_superposition/big_superposition_46 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_47
	time ./lem-in < resources/correct/big_superposition/big_superposition_47 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_48
	time ./lem-in < resources/correct/big_superposition/big_superposition_48 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_49
	time ./lem-in < resources/correct/big_superposition/big_superposition_49 > $sortie_verif && make check arg=$sortie_verif arg_2=$result
	echo resources/correct/big_superposition/big_superposition_50
	time ./lem-in < resources/correct/big_superposition/big_superposition_50 > $sortie_verif && make check arg=$sortie_verif arg_2=$result

fi

if [ "$1" = "error" ]
then
	$leak ./lem-in < resources/error/err_no_path.map 2>> $lem_in_error
	$leak ./lem-in < resources/error/impossible.txt 2>$lem_in_error
	$leak ./lem-in < resources/error/map_offi_no_way 2>> $lem_in_error
	$leak ./lem-in < resources/error/new_map 2>> $lem_in_error
	$leak ./lem-in < srcs 2>> $lem_in_error
	$leak ./lem-in < auteur 2>> $lem_in_error
	$leak ./lem-in < lem-in 2>> $lem_in_error
	$leak ./lem-in < resources/error/err_no_links.map 2>> $lem_in_error
	$leak ./lem-in < resources/error/2 2>> $lem_in_error
	$leak ./lem-in < resources/error/20.map 2>> $lem_in_error
	$leak ./lem-in < resources/error/bad_map 2>> $lem_in_error
	$leak ./lem-in < resources/error/bad_map_4 2>> $lem_in_error
	$leak ./lem-in < resources/error/comment.txt 2>> $lem_in_error
	$leak ./lem-in < resources/error/correct_gen_1 2>> $lem_in_error
	$leak ./lem-in < resources/error/correct_gen_2 2>> $lem_in_error
	$leak ./lem-in < resources/error/correct_gen_3 2>> $lem_in_error
	$leak ./lem-in < resources/error/correct_gen_4 2>> $lem_in_error
	$leak ./lem-in < resources/error/double_end.txt 2>> $lem_in_error
	$leak ./lem-in < resources/error/double_start.txt 2>> $lem_in_error
	$leak ./lem-in < resources/error/err_3_coordinates.map 2>> $lem_in_error
	$leak ./lem-in < resources/error/err_duplicate.map 2>> $lem_in_error
	$leak ./lem-in < resources/error/err_empty.map 2>> $lem_in_error
	$leak ./lem-in < resources/error/err_letter_in_coordinate.map 2>> $lem_in_error
	$leak ./lem-in < resources/error/err_link_to_unknown_room.map 2>> $lem_in_error
	$leak ./lem-in < resources/error/err_no_ants.map 2>> $lem_in_error
	$leak ./lem-in < resources/error/err_no_ants2.map 2>> $lem_in_error
	$leak ./lem-in < resources/error/err_no_ants3.map 2>> $lem_in_error
	$leak ./lem-in < resources/error/err_no_end2.map 2>> $lem_in_error
	$leak ./lem-in < resources/error/err_no_rooms.map 2>> $lem_in_error
	$leak ./lem-in < resources/error/err_no_start.map 2>> $lem_in_error
	$leak ./lem-in < resources/error/err_too_few_ants.map 2>> $lem_in_error
	$leak ./lem-in < resources/error/err_too_many_ants.map 2>> $lem_in_error
	$leak ./lem-in < resources/error/error2 2>> $lem_in_error
	$leak ./lem-in < resources/error/error3 2>> $lem_in_error
	$leak ./lem-in < resources/error/error4 2>> $lem_in_error
	$leak ./lem-in < resources/error/error5 2>> $lem_in_error
	$leak ./lem-in < resources/error/error6 2>> $lem_in_error
	$leak ./lem-in < resources/error/impossible2.txt 2>> $lem_in_error
	$leak ./lem-in < resources/error/invalid_pipe.txt 2>> $lem_in_error
	$leak ./lem-in < resources/error/little.txt 2>> $lem_in_error
	$leak ./lem-in < resources/error/map_edit 2>> $lem_in_error
	$leak ./lem-in < resources/error/map_incorrect_gen 2>> $lem_in_error
	$leak ./lem-in < resources/error/map_multiple_pipe_from_one_room_to_another 2>> $lem_in_error
	$leak ./lem-in < resources/error/no_end.txt 2>> $lem_in_error
	$leak ./lem-in < resources/error/no_start.txt 2>> $lem_in_error
	$leak ./lem-in < resources/error/norooms 2>> $lem_in_error
	$leak ./lem-in < resources/error/test.txt 2>> $lem_in_error
	$leak ./lem-in < resources/error/wrong_map_empty 2>> $lem_in_error
	$leak ./lem-in < resources/error/wrongmap_map_multiple_end 2>> $lem_in_error
	$leak ./lem-in < resources/error/wrongmap_multiple_start 2>> $lem_in_error
	$leak ./lem-in < resources/error/wrongmap_nawak 2>> $lem_in_error
	$leak ./lem-in < resources/error/wrongmap_no_way_to_the_end 2>> $lem_in_error
	$leak ./lem-in < resources/error/wrongmap_noant 2>> $lem_in_error
	$leak ./lem-in < resources/error/wrongmap_noend 2>> $lem_in_error
	$leak ./lem-in < resources/error/wrongmap_noend_nostart 2>> $lem_in_error
	$leak ./lem-in < resources/error/wrongmap_nopipe 2>> $lem_in_error
	$leak ./lem-in < resources/error/wrongmap_noroom 2>> $lem_in_error
	$leak ./lem-in < resources/error/wrongmap_nostart 2>> $lem_in_error
	$leak ./lem-in < resources/error/wrongmap_start_end 2>> $lem_in_error
	$leak ./lem-in < resources/error/wrongmap_wrong_ant 2>> $lem_in_error
	$leak ./lem-in < resources/error/wrongmap_wrong_coordonne 2>> $lem_in_error
	$leak ./lem-in < resources/error/wrongmap_wrong_pipe_name 2>> $lem_in_error
	$leak ./lem-in < resources/error/wrongmap_wrong_room_name 2>> $lem_in_error
	$leak ./lem-in < resources/error/wrongmap_wrong_room_name_2 2>> $lem_in_error
	$leak ./lem-in < resources/error/wrongmap_zero_ant 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_1 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_2 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_3 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_4 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_5 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_6 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_7 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_8 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_9 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_10 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_11 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_12 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_13 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_14 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_15 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_16 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_17 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_18 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_19 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_20 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_21 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_22 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_23 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_24 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_25 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_26 2>> $lem_in_error
	$leak ./lem-in < resources/error/error_27 2>> $lem_in_error
	$leak ./lem-in < resources/error/map_offi_pipe_error 2>> $lem_in_error
fi

echo "done"
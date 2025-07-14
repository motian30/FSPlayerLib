/*
 * FSPlayer.h
 *
 * Copyright (c) 2013 Bilibili
 * Copyright (c) 2013 Zhang Rui <bbcallen@gmail.com>
 * Copyright (c) 2019 debugly <qianlongxu@gmail.com>
 *
 * This file is part of FSPlayer.
 *
 * FSPlayer is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * FSPlayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FSPlayer; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#import <FSPlayer/FSMediaPlayback.h>
#import <FSPlayer/FSMonitor.h>
#import <FSPlayer/FSOptions.h>
#import <FSPlayer/FSVideoRenderingProtocol.h>
#import <FSPlayer/FSPlayerCore.h>


#if TARGET_OS_IOS || TARGET_OS_TV
#import <FSPlayer/SEIRenderView.h>
#else
#endif
// media meta
#define FS_KEY_FORMAT               @"format"
#define FS_KEY_DURATION_US          @"duration_us"
#define FS_KEY_START_US             @"start_us"
#define FS_KEY_BITRATE              @"bitrate"
#define FS_KEY_ENCODER              @"encoder"
#define FS_KEY_MINOR_VER            @"minor_version"
#define FS_KEY_COMPATIBLE_BRANDS    @"compatible_brands"
#define FS_KEY_MAJOR_BRAND          @"major_brand"
#define FS_KEY_LYRICS               @"LYRICS"
#define FS_KEY_ARTIST               @"artist"
#define FS_KEY_ALBUM                @"album"
#define FS_KEY_TYER                 @"TYER"
//icy header
#define FS_KEY_ICY_BR               @"icy-br"
#define FS_KEY_ICY_DESC             @"icy-description"
#define FS_KEY_ICY_GENRE            @"icy-genre"
#define FS_KEY_ICY_NAME             @"icy-name"
#define FS_KEY_ICY_PUB              @"icy-pub"
#define FS_KEY_ICY_URL              @"icy-url"
//icy meta
#define FS_KEY_ICY_ST               @"StreamTitle"
#define FS_KEY_ICY_SU               @"StreamUrl"

// stream meta
#define FS_KEY_STREAM_TYPE          @"type"
#define FS_VAL_TYPE__VIDEO          @"video"
#define FS_VAL_TYPE__AUDIO          @"audio"
#define FS_VAL_TYPE__SUBTITLE       @"timedtext"
#define FS_VAL_TYPE__UNKNOWN        @"unknown"

#define FS_KEY_CODEC_NAME           @"codec_name"
#define FS_KEY_CODEC_PROFILE        @"codec_profile"
#define FS_KEY_CODEC_LONG_NAME      @"codec_long_name"
#define FS_KEY_STREAM_IDX           @"stream_idx"

// stream: video
#define FS_KEY_WIDTH                @"width"
#define FS_KEY_HEIGHT               @"height"
#define FS_KEY_FPS_NUM              @"fps_num"
#define FS_KEY_FPS_DEN              @"fps_den"
#define FS_KEY_TBR_NUM              @"tbr_num"
#define FS_KEY_TBR_DEN              @"tbr_den"
#define FS_KEY_SAR_NUM              @"sar_num"
#define FS_KEY_SAR_DEN              @"sar_den"

// stream: audio
#define FS_KEY_SAMPLE_RATE          @"sample_rate"
#define FS_KEY_DESCRIBE             @"describe"
//audio meta also has "title" and "language" key
//#define FS_KEY_TITLE          @"title"
//#define FS_KEY_LANGUAGE       @"language"

// stream: subtitle
#define FS_KEY_TITLE                @"title"
#define FS_KEY_LANGUAGE             @"language"
#define FS_KEY_EX_SUBTITLE_URL      @"ex_subtile_url"
#define FS_KEY_STREAMS              @"streams"



